#ifndef __GLC_TEXTURE_CUBE_H__
#define __GLC_TEXTURE_CUBE_H__

#include <GL/glew.h>

class glcTextureCube
{
	GLuint m_ID;

	float m_Rotations[6][6];

	bool b_Initialized;

public:
	glcTextureCube();

	void init(const float& _pX = 0.0f, const float& _pY = 0.0f, const float& _pZ = 0.0f);
	void generate(const float& _pX = 0.0f, const float& _pY = 0.0f, const float& _pZ = 0.0f);
	//void ndGenerate(const float& _pX = 0.0f, const float& _pY = 0.0f, const float& _pZ = 0.0f);

	void use();

	void deinit();

	~glcTextureCube();
};

#endif