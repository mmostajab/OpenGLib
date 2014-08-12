#ifndef __GLC_TEXTURE2D__
#define __GLC_TEXTURE2D__

#include <GL/glew.h>

class glcTexture2D
{
private:
	GLuint m_ID;

public:
	glcTexture2D();

	void init();

	void deinit();

	~glcTexture2D();

};

#endif