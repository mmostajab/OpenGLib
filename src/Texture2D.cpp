#include "Texture2D.h"

#include <iostream>

#include "targa.h"

glcTexture2D::glcTexture2D()
{
}

glcTexture2D::glcTexture2D(const char* _pImgFilename)
{
	m_TextureFilename = _pImgFilename;
}

void glcTexture2D::init(const char* _pImgFilename)
{
	TargaImage textureImg;

	m_TextureFilename = _pImgFilename;
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
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, textureImg.getWidth(), 
		textureImg.getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, textureImg.getImageData());

	b_Initialized = true;
}

void glcTexture2D::init()
{
	TargaImage textureImg;

	if(!textureImg.load(m_TextureFilename))
	{
		std::cerr << "Could not load the texture" << std::endl;
		b_Initialized = false;
		return;
	}

	glGenTextures(1, &m_ID);
	glBindTexture(GL_TEXTURE_2D, m_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, textureImg.getWidth(), 
		textureImg.getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, textureImg.getImageData());

	b_Initialized = true;
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

void glcTexture2D::beginFishEyeRendering(const int& _pResW, const int& _pResH)
{
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);
  
  m_PreResW = viewport[2];
  m_PreResH = viewport[3];
  
  m_RenderTexH = m_RenderTexW = _pResW;
  if(_pResH != 1)
    m_RenderTexH = _pResH;
  
  glViewport(0, 0, m_RenderTexW, m_RenderTexH);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluPerspective(90, static_cast<float>(m_RenderTexW) / static_cast<float>(m_RenderTexH), 0.1f, 100.0f);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void glcTexture2D::finishFishEyeRendering()
{
  if(b_Initialized)
  {
    
  }
}

glcTexture2D::~glcTexture2D()
{
}