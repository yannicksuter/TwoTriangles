#include "twotriangles.h"

class Shader {
public:
	Shader();
	~Shader();
				
	void destroy();
	
	void disable();
	void enable();
	
	void enableVertexAttribArray(const char *pszName);
	
	const std::string &lastError() const;

	bool link();
	
	bool loadFragmentShader(const char *pszFilename);
	bool loadVertexShader(const char *pszFilename);

	GLuint programObject() const;

	void uniform1(const char *pszName, GLfloat v0);
	void uniform1(const char *pszName, GLint v0);
	void uniform1(const char *pszName, GLuint v0);
	void uniform1(const char *pszName, GLsizei count, const GLfloat *value);
	void uniform1(const char *pszName, GLsizei count, const GLint *value);
	void uniform1(const char *pszName, GLsizei count, const GLuint *value);

	void uniform2(const char *pszName, GLfloat v0, GLfloat v1);
	void uniform2(const char *pszName, GLint v0, GLint v1);
	void uniform2(const char *pszName, GLuint v0, GLuint v1);
	void uniform2(const char *pszName, GLsizei count, const GLfloat *value);
	void uniform2(const char *pszName, GLsizei count, const GLint *value);
	void uniform2(const char *pszName, GLsizei count, const GLuint *value);
	
	void uniform3(const char *pszName, GLfloat v0, GLfloat v1, GLfloat v2);
	void uniform3(const char *pszName, GLint v0, GLint v1, GLint v2);
	void uniform3(const char *pszName, GLuint v0, GLuint v1, GLuint v2);
	void uniform3(const char *pszName, GLsizei count, const GLfloat *value);
	void uniform3(const char *pszName, GLsizei count, const GLint *value);
	void uniform3(const char *pszName, GLsizei count, const GLuint *value);
	
	void uniform4(const char *pszName, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	void uniform4(const char *pszName, GLint v0, GLint v1, GLint v2, GLint v3);
	void uniform4(const char *pszName, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	void uniform4(const char *pszName, GLsizei count, const GLfloat *value);
	void uniform4(const char *pszName, GLsizei count, const GLint *value);
	void uniform4(const char *pszName, GLsizei count, const GLuint *value);
	
	void uniformMatrix2(const char *pszName, GLsizei count, GLboolean transpose, const GLfloat *value);
	void uniformMatrix2x3(const char *pszName, GLsizei count, GLboolean transpose, const GLfloat *value);
	void uniformMatrix2x4(const char *pszName, GLsizei count, GLboolean transpose, const GLfloat *value);
	
	void uniformMatrix3(const char *pszName, GLsizei count, GLboolean transpose, const GLfloat *value);
	void uniformMatrix3x2(const char *pszName, GLsizei count, GLboolean transpose, const GLfloat *value);
	void uniformMatrix3x4(const char *pszName, GLsizei count, GLboolean transpose, const GLfloat *value);
	
	void uniformMatrix4(const char *pszName, GLsizei count, GLboolean transpose, const GLfloat *value);
	void uniformMatrix4x2(const char *pszName, GLsizei count, GLboolean transpose, const GLfloat *value);
	void uniformMatrix4x3(const char *pszName, GLsizei count, GLboolean transpose, const GLfloat *value);

	void vertexAttrib1(const char *pszName, GLdouble x);
	void vertexAttrib1(const char *pszName, GLfloat x);
	void vertexAttrib1(const char *pszName, GLshort x);
	void vertexAttrib1(const char *pszName, const GLdouble *v);
	void vertexAttrib1(const char *pszName, const GLfloat *v);
	void vertexAttrib1(const char *pszName, const GLshort *v);
	
	void vertexAttrib2(const char *pszName, GLdouble x, GLdouble y);
	void vertexAttrib2(const char *pszName, GLfloat x, GLfloat y);
	void vertexAttrib2(const char *pszName, GLshort x, GLshort y);
	void vertexAttrib2(const char *pszName, const GLdouble *v);
	void vertexAttrib2(const char *pszName, const GLfloat *v);
	void vertexAttrib2(const char *pszName, const GLshort *v);
	
	void vertexAttrib3(const char *pszName, GLdouble x, GLdouble y, GLdouble z);
	void vertexAttrib3(const char *pszName, GLfloat x, GLfloat y, GLfloat z);
	void vertexAttrib3(const char *pszName, GLshort x, GLshort y, GLshort z);
	void vertexAttrib3(const char *pszName, const GLdouble *v);
	void vertexAttrib3(const char *pszName, const GLfloat *v);
	void vertexAttrib3(const char *pszName, const GLshort *v);
	
	void vertexAttrib4(const char *pszName, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void vertexAttrib4(const char *pszName, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void vertexAttrib4(const char *pszName, GLshort x, GLshort y, GLshort z, GLshort w);
	void vertexAttrib4(const char *pszName, const GLbyte *v);
	void vertexAttrib4(const char *pszName, const GLdouble *v);
	void vertexAttrib4(const char *pszName, const GLfloat *v);
	void vertexAttrib4(const char *pszName, const GLint *v);
	void vertexAttrib4(const char *pszName, const GLshort *v);
	void vertexAttrib4(const char *pszName, const GLubyte *v);
	void vertexAttrib4(const char *pszName, const GLuint *v);
	void vertexAttrib4(const char *pszName, const GLushort *v);
	
	void vertexAttrib4N(const char *pszName, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	void vertexAttrib4N(const char *pszName, const GLbyte *v);
	void vertexAttrib4N(const char *pszName, const GLint *v);
	void vertexAttrib4N(const char *pszName, const GLshort *v);
	void vertexAttrib4N(const char *pszName, const GLubyte *v);
	void vertexAttrib4N(const char *pszName, const GLuint *v);
	void vertexAttrib4N(const char *pszName, const GLushort *v);
	
	void vertexAttribI1(const char *pszName, GLint x);
	void vertexAttribI1(const char *pszName, GLuint x);
	void vertexAttribI1(const char *pszName, const GLint *v);
	void vertexAttribI1(const char *pszName, const GLuint *v);
	
	void vertexAttribI2(const char *pszName, GLint x, GLint y);
	void vertexAttribI2(const char *pszName, GLuint x, GLuint y);
	void vertexAttribI2(const char *pszName, const GLint *v);
	void vertexAttribI2(const char *pszName, const GLuint *v);
	
	void vertexAttribI3(const char *pszName, GLint x, GLint y, GLint z);
	void vertexAttribI3(const char *pszName, GLuint x, GLuint y, GLuint z);
	void vertexAttribI3(const char *pszName, const GLint *v);
	void vertexAttribI3(const char *pszName, const GLuint *v);
	
	void vertexAttribI4(const char *pszName, GLint x, GLint y, GLint z, GLint w);
	void vertexAttribI4(const char *pszName, GLuint x, GLuint y, GLuint z, GLuint w);
	void vertexAttribI4(const char *pszName, const GLbyte *v);
	void vertexAttribI4(const char *pszName, const GLint *v);
	void vertexAttribI4(const char *pszName, const GLshort *v);
	void vertexAttribI4(const char *pszName, const GLubyte *v);
	void vertexAttribI4(const char *pszName, const GLuint *v);
	void vertexAttribI4(const char *pszName, const GLushort *v);
	void vertexAttribIPointer(const char *pszName, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	
	void vertexAttribP1(const char *pszName, GLenum type, GLboolean normalized, GLuint value);
	void vertexAttribP1(const char *pszName, GLenum type, GLboolean normalized, const GLuint *value);
	void vertexAttribP2(const char *pszName, GLenum type, GLboolean normalized, GLuint value);
	void vertexAttribP2(const char *pszName, GLenum type, GLboolean normalized, const GLuint *value);
	void vertexAttribP3(const char *pszName, GLenum type, GLboolean normalized, GLuint value);
	void vertexAttribP3(const char *pszName, GLenum type, GLboolean normalized, const GLuint *value);
	void vertexAttribP4(const char *pszName, GLenum type, GLboolean normalized, GLuint value);
	void vertexAttribP4(const char *pszName, GLenum type, GLboolean normalized, const GLuint *value);
	void vertexAttribPointer(const char *pszName, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);

private:
	Shader(const Shader &);
	Shader &operator=(const Shader &);

	void compileError(const char *pszFilename, GLenum shaderType, GLuint shader);
	void compileError(int resourceId, GLenum shaderType, GLuint shader);
	void createProgram();
	void deleteShaders(const std::map<std::string, GLuint> &shaders) const;
	void deleteShaders(const std::map<int, GLuint> &shaders) const;
	void error(std::string msg);
	GLint getAttribLocation(const char *pszName);
	std::string getProgramInfoLog(GLuint program) const;
	std::string getShaderInfoLog(GLuint shader) const;
	GLint getUniformLocation(const char *pszName);
	bool loadShader(const char *pszFilename, GLenum shaderType);

	GLuint m_program;
	std::string m_lastError;
	std::map<std::string, GLuint> m_fileVertexShaders;
	std::map<std::string, GLuint> m_fileFragmentShaders;
	std::map<int, GLuint> m_resourceVertexShaders;
	std::map<int, GLuint> m_resourceFragmentShaders;
};