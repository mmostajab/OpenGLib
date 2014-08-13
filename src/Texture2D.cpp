#include "Texture2D.h"

#include <iostream>

#include "targa.h"

glcTexture2D::glcTexture2D()
{
}

void glcTexture2D::init(const char* _pImgFilename)
{
	TargaImage textureImg;

	if(!textureImg.load(_pImgFilename))
	{
		std::cerr << "Could not load the texture" << std::endl;
		b_Initialized = false;
		return;
	}

	glGenTextures(1, &m_ID);
	glBindTexture(GL_TEXTURE_2D, m_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, textureImg.getWidth(), 
		textureImg.getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, textureImg.getImageData());
}

void glcTexture2D::use()
{
	if(b_Initialized)
		glBindTexture(GL_TEXTURE_2D, m_ID);
}

void glcTexture2D::deinit()
{
	glDeleteTextures(1, &m_ID);
}

glcTexture2D::~glcTexture2D()
{

}