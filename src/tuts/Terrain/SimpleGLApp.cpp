#include "SimpleGLApp.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>

SimpleGLApp::SimpleGLApp(const int& _pWidth, const int& _pHeight): GLApp(_pWidth, _pHeight)
{
	m_ShaderProgram = new glcShaderProgram("../src/simple.vert", "../src/simple.frag");
}
void SimpleGLApp::init()
{
	GLApp::init();

	m_Terrain.init("heightmap.raw", 65);
	m_Texture.init("textureLBP.tga");

	m_ShaderProgram->init();
	if(!m_ShaderProgram->isInitialized())
	{
		// Sth is wrong...
	}

	// Bind Share Attributes
	m_ShaderProgram->bindAttribute(0, "a_Vertex");
	m_ShaderProgram->bindAttribute(1, "a_Color");
	m_ShaderProgram->bindAttribute(2, "a_TexCoord");

	// Re-link the program
	m_ShaderProgram->link();
	m_ShaderProgram->use();

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	m_Texture.use();
}

void SimpleGLApp::prepare(const float& _pDeltaTime)
{
	glGetFloatv(GL_MODELVIEW_MATRIX, m_ModelViewMat);
	glGetFloatv(GL_PROJECTION_MATRIX, m_ProjectionMat);

	m_ShaderProgram->sendUniformMatrix4fv("modelview_matrix", m_ModelViewMat);
	m_ShaderProgram->sendUniformMatrix4fv("projection_matrix", m_ProjectionMat);
	m_ShaderProgram->sendUniform("texture0", 0);
}

void SimpleGLApp::render()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glTranslatef(0.0f, -20.0f, 0.0f);
    glRotatef(25.0f, 1.0f, 0.0f, 0.0f);
    //Translate using our zPosition variable
    glTranslatef(0.0, 0.0, -50.0f);

	m_Terrain.render();
}

void SimpleGLApp::shutdown()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	m_Texture.deinit();
	delete m_ShaderProgram;
}

void SimpleGLApp::onResize(const int& _pWidth, const int& _pHeight)
{
	GLApp::onResize(_pWidth, _pHeight);
}

SimpleGLApp::~SimpleGLApp()
{
}