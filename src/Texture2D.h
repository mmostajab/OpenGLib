#ifndef __GLC_TEXTURE2D__
#define __GLC_TEXTURE2D__

#include <GL/glew.h>
#include <string>

class glcTexture2D
{
private:
	GLuint m_ID;
	std::string m_TextureFilename;

	bool b_Initialized;

public:
	glcTexture2D();
	glcTexture2D(const char* _pImgFilename);

	void init(const char* _pImgFilename);
	void init();

	void use();

	void deinit();

	~glcTexture2D();
};

#endif