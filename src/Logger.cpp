#include "twotriangles.h"

Logger* Logger::m_pInstance = NULL;

Logger*  Logger::GetInstance() {
	if (m_pInstance == NULL) {
		m_pInstance = new Logger();
	}
	return m_pInstance;
}

Logger::Logger(void) {
	m_bConsoleOutput = true;
	m_bShowErrorContext = false;
	m_pFile = stdout;
}

Logger::~Logger(void) {
	Release();
}

void Logger::Initialize(char *pfileName) {
	if (pfileName != NULL) {
		m_pFile = fopen(pfileName, "w");
		if (m_pFile != NULL)
			fseek(m_pFile, 0, SEEK_END);
		m_bConsoleOutput = false;
	}
}

void Logger::Release() {
	if (m_pFile != NULL)
		fclose(m_pFile);
	m_pFile = NULL;
}

std::string format_(std::string format, va_list args) {
	va_list args_copy;
	va_copy(args_copy, args);

	const auto sz = std::vsnprintf(nullptr, 0, format.c_str(), args) + 1;
	try {
		std::string result(sz, ' ');
		std::vsnprintf(&result.front(), sz, format.c_str(), args_copy);
		va_end(args_copy);
		return result;
	} catch (const std::bad_alloc&) {
		va_end(args_copy);
		throw;
	}
}

std::string format(std::string format, ...) {
	va_list args, args_copy;
	va_start(args, format);
	va_copy(args_copy, args);

	const auto sz = std::vsnprintf(nullptr, 0, format.c_str(), args) + 1;
	try {
		std::string result(sz, ' ');
		std::vsnprintf(&result.front(), sz, format.c_str(), args_copy);
		va_end(args_copy);
		va_end(args);
		return result;
	}
	catch (const std::bad_alloc&) {
		va_end(args_copy);
		va_end(args);
		throw;
	}
}

const std::string currentTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);
    return buf;
}

void Logger::Write(char *pType, char *pFileName, int lineNo, char *msg, ...) {
	if (m_pFile != NULL) {
		if (msg != NULL) {
			va_list vlist;
			va_start(vlist, msg); 
			std::string message = format_(msg, vlist);
			va_end(vlist);

			std::string errorLine;
			if (m_bShowErrorContext) {
				errorLine = format("%s %s %s (%s:%d)", (const char*)pType, currentTime().c_str(), message.c_str(), pFileName, lineNo);
			} else {
				errorLine = format("%s %s %s", (const char*)pType, currentTime().c_str(), message.c_str());
			}

			fprintf(m_pFile, "%s\n", errorLine.c_str());
			fflush(m_pFile);
		}
	}
}

void Logger::WriteAbort(char *pTest, char *pFileName, int lineNo, char *msg, ...) {
	if (m_pFile != NULL) {
		va_list vlist;
		va_start(vlist, msg);
		std::string message = format_(msg, vlist);
		va_end(vlist);

		std::string errorLine = format("%s, %s (%s:%d)", (const char*)pTest, message.c_str(), pFileName, lineNo);
		fprintf(m_pFile, "%s\n", errorLine.c_str());
		fflush(m_pFile);
		abort();
	}
}
