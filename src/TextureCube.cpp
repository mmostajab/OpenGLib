#include "TextureCube.h"

#include <iostream>

glcTextureCube::glcTextureCube()
{
//   { 1.0, 0.0, 0.0,   0.0, -1.0, 0.0 },  // pos x
//       { -1.0, 0.0, 0.0,  0.0, -1.0, 0.0 },  // neg x
//       { 0.0, 1.0, 0.0,   0.0, 0.0, 1.0 },   // pos y
//       { 0.0, -1.0, 0.0,  0.0, 0.0, -1.0 },  // neg y
//       { 0.0, 0.0, 1.0,   0.0, -1.0, 0.0 },  // poz z
//       { 0.0, 0.0, -1.0,  0.0, -1.0, 0.0 }   // neg z
  
  m_Rotations[0][0] =  1;m_Rotations[0][1] =  0;m_Rotations[0][2] =  0;m_Rotations[0][3] = 0;m_Rotations[0][4] =  1;m_Rotations[0][5] =  0;
  m_Rotations[1][0] = -1;m_Rotations[1][1] =  0;m_Rotations[1][2] =  0;m_Rotations[1][3] = 0;m_Rotations[1][4] =  1;m_Rotations[1][5] =  0;
  m_Rotations[2][0] =  0;m_Rotations[2][1] =  1;m_Rotations[2][2] =  0;m_Rotations[2][3] = 0;m_Rotations[2][4] =  0;m_Rotations[2][5] =  1;
  m_Rotations[3][0] =  0;m_Rotations[3][1] = -1;m_Rotations[3][2] =  0;m_Rotations[3][3] = 0;m_Rotations[3][4] =  0;m_Rotations[3][5] = -1;
  m_Rotations[4][0] =  0;m_Rotations[4][1] =  0;m_Rotations[4][2] =  1;m_Rotations[4][3] = 0;m_Rotations[4][4] =  1;m_Rotations[4][5] =  0;
  m_Rotations[5][0] =  0;m_Rotations[5][1] =  0;m_Rotations[5][2] = -1;m_Rotations[5][3] = 0;m_Rotations[5][4] =  1;m_Rotations[5][5] =  0;
}

void glcTextureCube::init(const float& _pX, const float& _pY, const float& _pZ)
{
  glGenTextures(1, &m_ID);
  glBindTexture(GL_TEXTURE_CUBE_MAP, m_ID);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  m_X = _pX;	m_Y = _pY;	m_Z = _pZ;
  
//   generate(_pX, _pY, _pZ);
  //b_Initialized = true;
}

void glcTextureCube::use()
{
  glBindTexture(GL_TEXTURE_CUBE_MAP, m_ID);
}

void glcTextureCube::deinit()
{

}

void glcTextureCube::setPosition(const float& _pX, const float& _pY, const float& _pZ)
{
  m_X = _pX;
  m_Y = _pY;
  m_Z = _pZ;
}

void glcTextureCube::beginCubeMapRendering(const int& _pResW, const int& _pResH)
{
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);
  m_PreWidth = viewport[2];
  m_PreHeight = viewport[3];

  m_RenderTexH = m_RenderTexW = _pResW;
  
  if(_pResH != -1)
    m_RenderTexH = _pResH;
  
  glViewport(0, 0, m_RenderTexW, m_RenderTexH);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluPerspective(90, static_cast<float>(m_RenderTexW) / static_cast<float>(m_RenderTexH), 0.1, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
}
void glcTextureCube::beginCubeMapFaceRender(const int& _pIdx)
{
  glBindTexture(GL_TEXTURE_CUBE_MAP, m_ID);
  
 // glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(	m_X, m_Y, m_Z, 
	  m_X + m_Rotations[_pIdx][0], m_Y + m_Rotations[_pIdx][1], m_Z + m_Rotations[_pIdx][2], 
	  m_Rotations[_pIdx][3], m_Rotations[_pIdx][4], m_Rotations[_pIdx][5]);  
  
  // std::cout << m_X + m_Rotations[_pIdx][0] << ", " << m_Y + m_Rotations[_pIdx][1] << ", " << m_Z + m_Rotations[_pIdx][2] << std::endl;
}

void glcTextureCube::finishCubeMapFaceRender(const int& _pIdx)
{
  glBindTexture(GL_TEXTURE_CUBE_MAP, m_ID);
  if(b_Initialized)
  {
    glCopyTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + _pIdx, 0, 0, 0, 0, 0, m_RenderTexW, m_RenderTexH);
  }
  else
  {
    glCopyTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + _pIdx, 0, GL_RGB8, 0, 0, m_RenderTexW, m_RenderTexH, 0);
  }
}

void glcTextureCube::finishCubeMapRendering()
{
  b_Initialized = true;
  
  glViewport(0, 0, m_PreWidth, m_PreHeight);

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}

glcTextureCube::~glcTextureCube()
{

}