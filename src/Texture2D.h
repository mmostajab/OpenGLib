#ifndef __GLC_TEXTURE2D__
#define __GLC_TEXTURE2D__

#include <GL/glew.h>

class glcTexture2D
{
private:
	GLuint m_ID;

	bool b_Initialized;

public:
	glcTexture2D();


	void init(const char* _pImgFilename);

	void use();

	void deinit();

	~glcTexture2D();

};

#endif