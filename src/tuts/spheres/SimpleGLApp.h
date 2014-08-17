#ifndef __SIMPLE_GL_APP__
#define __SIMPLE_GL_APP__

#include "GLApp.h"
#include <vector>

#include "Texture2D.h"
#include "TextureCube.h"
#include "ShaderProgram.h"
#include "Terrain.h"
#include "Sphere.h"

class SimpleGLApp: public GLApp
{
private:
	glcShaderProgram* m_ShaderProgram;
	float m_ModelViewMat[16], m_ProjectionMat[16];
	Terrain3D m_Terrain;
	glcTexture2D m_Texture;

	float m_RotVal;

	Sphere3D m_TexdSphere;
	Sphere3D m_CubeMapSphere;


public:
	SimpleGLApp(const int& _pWidth = 640, const int& _pHeight = 480);

	virtual void init();
	virtual void prepare(const float& _pDeltaTime);
	virtual void render();
	virtual void shutdown();
	virtual void onResize(const int& _pWidth, const int& _pHeight);

	~SimpleGLApp();
};

#endif