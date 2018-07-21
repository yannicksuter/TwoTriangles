#include "twotriangles.h"

#define __SHORT_FILE__ (strrchr((char*)__FILE__,'\\') ? strrchr((char*)__FILE__,'\\')+1 : (char*)__FILE__)

#define LOG_VERBOSE(...) Logger::GetInstance()->Write("[v]", __SHORT_FILE__, __LINE__, __VA_ARGS__);
#define LOG_MSG(...) Logger::GetInstance()->Write("[i]", __SHORT_FILE__, __LINE__, __VA_ARGS__);
#define LOG_WARN(...) Logger::GetInstance()->Write("[w]", __SHORT_FILE__, __LINE__, __VA_ARGS__);
#define LOG_ERR(...) Logger::GetInstance()->Write("[e]", __SHORT_FILE__, __LINE__, __VA_ARGS__);
#define LOG_FATAL(...) Logger::GetInstance()->Write("[!]", __SHORT_FILE__, __LINE__, __VA_ARGS__);

#define ASSERT(test, ...) ASSERT_WITH_INFO(test, #test, ##__VA_ARGS__)
#define ASSERT_WITH_INFO(test, info, ...) (test == true) ? (void)0 : Logger::GetInstance()->WriteAbort("CHECK FAILED: " info " ", __SHORT_FILE__, __LINE__, ##__VA_ARGS__)

class Logger {
public:
	static Logger* GetInstance();
	void Initialize(char *pfileName);

	void Write(char *pType, char *pFileName, int lineNo, char *msg, ...);
	void WriteAbort(char *pTest, char *pFileName, int lineNo, char *msg, ...);

private:
	Logger();
	~Logger();

	void Release();

	bool m_bConsoleOutput;
	bool m_bShowErrorContext;
	FILE *m_pFile;

	static Logger *m_pInstance;
};