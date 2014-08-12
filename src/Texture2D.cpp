#include "Texture2D.h"

glcTexture2D::glcTexture2D()
{

}

void glcTexture2D::init()
{
	glGenTextures(1, &m_ID);
}

void glcTexture2D::deinit()
{
	glDeleteTextures(1, &m_ID);
}

glcTexture2D::~glcTexture2D()
{

}