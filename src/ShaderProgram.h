#ifndef __GLC_SHADER_PROGRAM__
#define __GLC_SHADER_PROGRAM__

#include <GL/glew.h>

#include <string>
#include <map>

struct glcShaderInfo
{
	GLuint id;
	std::string fileName;
	std::string source;
};

class glcShaderProgram
{
private:
	GLuint m_ProgramID;

	glcShaderInfo m_VS, m_FS;
	bool b_Initialized;

	std::map<std::string, GLuint> m_UniformsMap;
	std::map<std::string, GLuint> m_AttributesMap;

public:
	glcShaderProgram(const char* _pVSFileName, const char* _pFSFileName);

	void init();
	void init(const std::string& _pShaderHeader);

	void link();
	void use();

	GLuint getUniformLocation(const std::string& _pUniformName);
	GLuint getAttributeLocation(const std::string& _pAttributeName);

	void sendUniform(const std::string& _pUniformName, const int& _pId);
	void sendUniformMatrix4fv(const std::string& _pUniformName, const float* _pMatrixPtr, bool _pTranspose = false);
	void sendUniform3fv(const std::string& _pUniformName, const float& _pV1, const float& _pV2, const float& _pV3);
	void bindAttribute(const unsigned int& _pIndex, const std::string& _pAttributeName);

	void deinit();

	bool isInitialized();

	~glcShaderProgram();

private:
	std::string readFile(const std::string& _pFileName);
	bool compileShader(const glcShaderInfo& _pShaderInfo);
	void outputShaderLog(const glcShaderInfo& _pShaderInfo);
};

#endif