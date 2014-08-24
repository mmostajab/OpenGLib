#ifndef __GLC_TEXTURE_CUBE_H__
#define __GLC_TEXTURE_CUBE_H__

#include <GL/glew.h>

class glcTextureCube
{
	GLuint m_ID;

	float m_X, m_Y, m_Z;
	float m_Rotations[6][6];
	int m_RenderTexW, m_RenderTexH;
	int m_PreWidth, m_PreHeight;
	
	bool b_Initialized;

public:
	glcTextureCube();

	void init(const float& _pX = 0.0f, const float& _pY = 0.0f, const float& _pZ = 0.0f);
// 	void generate(const float& _pX = 0.0f, const float& _pY = 0.0f, const float& _pZ = 0.0f);
	//void ndGenerate(const float& _pX = 0.0f, const float& _pY = 0.0f, const float& _pZ = 0.0f);

	void use();

	void deinit();
	
	void setPosition(const float& _pX, const float& _pY, const float& _pZ);

	// To generate the cube map we have to use this functions
	void beginCubeMapRendering(const int& _pResW = 512, const int& _pResH = -1);
	void beginCubeMapFaceRender(const int& _pIdx);
        void finishCubeMapFaceRender(const int& _pIdx);
	void finishCubeMapRendering();

	~glcTextureCube();
};

#endif