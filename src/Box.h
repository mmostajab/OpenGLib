#ifndef __BOX_3D_H__
#define __BOX_3D_H__

#include <GL/glew.h>

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "TextureCube.h"

#include <string>
#include <math.h>

struct BoxVert
{
	float x, y, z;
	float s, t;
	float nx, ny, nz;

	BoxVert(const float& _pX, const float& _pY, const float& _pZ, const float& _pS, const float& _pT, const float& _pNx, const float& _pNy, const float& _pNz):
	    x(_pX), y(_pY), z(_pZ), s(_pS), t(_pT), nx(_pNx), ny(_pNy), nz(_pNz)
	{
	      
	}

	void normalizeNormal()
	{
		float l2 = nx * nx + ny * ny + nz * nz;
		float l = sqrt(l2);

		if(l > 0.0001f)
		{
			nx /= l;
			ny /= l;
			nz /= l;
		}
	}
};

class Box3D
{
private:
	GLuint m_BufferId;

	float m_Width;

	std::string m_ShaderHeader;
	glcShaderProgram* m_ShaderPrg;

	std::string m_TextureFilename;
	bool b_CubeMapping;
	bool b_Initialized;
	
	float m_X, m_Y, m_Z;
	float m_RotDeg;
 
	union {
		glcTexture2D* m_TexturePtr;
		glcTextureCube* m_CubeTexturePtr;
	};

public:
	Box3D(const float& _pWidth, const char* _pTextureFilename);
	Box3D(const float& _pWidth);

	void init(const float& _pX = 0.0f, const float& _pY = 0.0f, const float& _pZ = 0.0f);

	void render();

	void deinit();
	
	glcTextureCube* getTextureCubePtr();
	
	void setPosition(const float& _pX, const float& _pY, const float& _pZ);

	~Box3D();
};

#endif