#include "TextureCube.h"

glcTextureCube::glcTextureCube()
{
	m_Rotations[0][0] =  1;m_Rotations[0][1] =  0;m_Rotations[0][2] =  0;m_Rotations[0][3] = 0;m_Rotations[0][4] = -1;m_Rotations[0][5] =  0;
	m_Rotations[1][0] = -1;m_Rotations[1][1] =  0;m_Rotations[1][2] =  0;m_Rotations[1][3] = 0;m_Rotations[1][4] = -1;m_Rotations[1][5] =  0;
	m_Rotations[2][0] =  0;m_Rotations[2][1] =  1;m_Rotations[2][2] =  0;m_Rotations[2][3] = 0;m_Rotations[2][4] =  0;m_Rotations[2][5] =  1;
	m_Rotations[3][0] =  0;m_Rotations[3][1] = -1;m_Rotations[3][2] =  0;m_Rotations[3][3] = 0;m_Rotations[3][4] =  0;m_Rotations[3][5] = -1;
	m_Rotations[4][0] =  0;m_Rotations[4][1] =  0;m_Rotations[4][2] =  1;m_Rotations[4][3] = 0;m_Rotations[4][4] = -1;m_Rotations[4][5] =  0;
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

//	generate(_pX, _pY, _pZ);
	b_Initialized = true;
}

void glcTextureCube::generate(const float& _pX, const float& _pY, const float& _pZ)
{
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	int viewportW = viewport[2], viewportH = viewport[3];

	int texSize = 512;
	// Changing the viewport and Projection matrix to render the reflection maps
	glViewport(0, 0, texSize, texSize);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(90.0f, 1, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

	glBindTexture(GL_TEXTURE_CUBE_MAP, m_ID);
	for(int i = 0; i < 6; i++)
	{
		glClear(GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(	_pX, _pY, _pZ, 
					m_Rotations[i][0], m_Rotations[i][1], m_Rotations[i][2], 
					m_Rotations[i][3], m_Rotations[i][4], m_Rotations[i][5]);

		if(b_Initialized)
		{
			glCopyTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, 0, 0, 0, 0, texSize, texSize);
		}
		else
		{
			glCopyTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB8, 0, 0, texSize, texSize, 0);
		}

	}

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	// reset the viewport and projection matrix
	glViewport(0, 0, viewportW, viewportH);
	glMatrixMode(GL_MODELVIEW);
}

void glcTextureCube::use()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_ID);
}

void glcTextureCube::deinit()
{

}

glcTextureCube::~glcTextureCube()
{

}