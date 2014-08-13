#ifndef __SIMPLE_GL_APP__
#define __SIMPLE_GL_APP__

#include "GLApp.h"
#include <vector>

#include "VertexBuffer.h"
#include "Texture2D.h"
#include "ShaderProgram.h"

class SimpleGLApp: public GLApp
{
private:
	float m_RotationAngle;
	GLfloat* m_VertexBuff;
	std::vector<GLfloat> m_VertexVec;
	std::vector<float> m_ColorsVec;
	std::vector<int> m_IndicesVec;

	glcShaderProgram* m_ShaderProgram;
	float m_ModelViewMat[16], m_ProjectionMat[16];
	glcVertexBuffer m_VBO;
	glcTexture2D m_Texture;
	float m_RotTimer;
	float m_Axisx, m_Axisy, m_Axisz;

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