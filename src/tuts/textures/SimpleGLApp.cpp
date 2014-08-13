#include "SimpleGLApp.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "VertexArray.h"
#include "VertexBuffer.h"

SimpleGLApp::SimpleGLApp(const int& _pWidth, const int& _pHeight): GLApp(_pWidth, _pHeight)
{
	m_VertexBuff = new GLfloat[12];
	m_ShaderProgram = new glcShaderProgram("../src/simple.vert", "../src/simple.frag");

	m_RotTimer = 0.0f;

	m_Axisx = 0.0f;
	m_Axisy = 0.0f;
	m_Axisz = 1.0f;
}

void createPyramid(std::vector<GLfloat>& _pBuffer, std::vector<GLint>& _pIndices)
{
	_pBuffer.push_back( 0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back(-0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 1.0);

	_pIndices.push_back(0);	_pIndices.push_back(1);	_pIndices.push_back(3);
	_pIndices.push_back(1);	_pIndices.push_back(2);	_pIndices.push_back(3);
	
	_pIndices.push_back(0);	_pIndices.push_back(1);	_pIndices.push_back(4);
	_pIndices.push_back(1);	_pIndices.push_back(2);	_pIndices.push_back(4);
	_pIndices.push_back(2);	_pIndices.push_back(3);	_pIndices.push_back(4);
	_pIndices.push_back(1);	_pIndices.push_back(3);	_pIndices.push_back(4);
}

void createColoredPyramid(std::vector<GLfloat>& _pBuffer, std::vector<GLint>& _pIndices)
{
	_pBuffer.push_back( 0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);
	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back(-0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 1.0);
	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);
	_pBuffer.push_back( 0.5);	_pBuffer.push_back( 0.2);	_pBuffer.push_back( 0.3);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 1.0);

	_pIndices.push_back(0);	_pIndices.push_back(1);	_pIndices.push_back(3);
	_pIndices.push_back(1);	_pIndices.push_back(2);	_pIndices.push_back(3);
	
	_pIndices.push_back(0);	_pIndices.push_back(1);	_pIndices.push_back(4);
	_pIndices.push_back(1);	_pIndices.push_back(2);	_pIndices.push_back(4);
	_pIndices.push_back(2);	_pIndices.push_back(3);	_pIndices.push_back(4);
	_pIndices.push_back(0);	_pIndices.push_back(3);	_pIndices.push_back(4);
}

void createColoredTexturedPyramid(std::vector<GLfloat>& _pBuffer, std::vector<GLint>& _pIndices)
{
	_pBuffer.push_back( 0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);
	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 1.0);
	_pBuffer.push_back(-0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 1.0);
	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 1.0);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);
	_pBuffer.push_back( 0.5);	_pBuffer.push_back( 0.2);	_pBuffer.push_back( 0.3);
	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 1.0);	_pBuffer.push_back( 1.0);
	_pBuffer.push_back( 0.5);	_pBuffer.push_back( 0.5);

	_pIndices.push_back(0);	_pIndices.push_back(1);	_pIndices.push_back(3);
	_pIndices.push_back(1);	_pIndices.push_back(2);	_pIndices.push_back(3);
	
	_pIndices.push_back(0);	_pIndices.push_back(1);	_pIndices.push_back(4);
	_pIndices.push_back(1);	_pIndices.push_back(2);	_pIndices.push_back(4);
	_pIndices.push_back(2);	_pIndices.push_back(3);	_pIndices.push_back(4);
	_pIndices.push_back(0);	_pIndices.push_back(3);	_pIndices.push_back(4);
}

void createPyramid(std::vector<GLfloat>& _pBuffer)
{
	// Bottom 1
	_pBuffer.push_back(-0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back( 0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-1.0);
	
	// Bottom 2
	_pBuffer.push_back(-0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-1.0);

	// Left Part
	_pBuffer.push_back(-0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-1.0);

	// Down Part
	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-1.0);

	// Right Part
	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-0.3);	_pBuffer.push_back(-1.0);

	// Up Part
	_pBuffer.push_back(-0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-1.0);
	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);	_pBuffer.push_back( 0.0);
	_pBuffer.push_back( 0.3);	_pBuffer.push_back( 0.3);	_pBuffer.push_back(-1.0);
}

void SimpleGLApp::init()
{
	GLApp::init();

	m_VertexBuff[0] = -0.3f; m_VertexBuff[ 1] = -0.3f; m_VertexBuff[ 2] = -0.3f;
	m_VertexBuff[3] = -0.3f; m_VertexBuff[ 4] = -0.3f; m_VertexBuff[ 5] = -0.3f;
	m_VertexBuff[6] = -0.3f; m_VertexBuff[ 7] = -0.3f; m_VertexBuff[ 8] = -0.3f;
	m_VertexBuff[9] = -0.3f; m_VertexBuff[10] = -0.3f; m_VertexBuff[11] = -0.3f;

	m_Texture.init("textureLBP.tga");

	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);

	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(1.0f);
	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);

	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(1.0f);
	// m_ColorsVec.push_back(0.0f);

	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(1.0f);

	// m_IndicesVec.push_back(0);
	// m_IndicesVec.push_back(1);
	// m_IndicesVec.push_back(3);

	// m_IndicesVec.push_back(0);
	// m_IndicesVec.push_back(2);
	// m_IndicesVec.push_back(3);

	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);

	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(1.0f);
	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);

	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(1.0f);
	// m_ColorsVec.push_back(0.0f);

	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);

	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(1.0f);
	// m_ColorsVec.push_back(0.0f);

	// m_VertexVec.push_back(-0.3f);
	// m_VertexVec.push_back( 0.3f);
	// m_VertexVec.push_back(-1.0f);

	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(0.0f);
	// m_ColorsVec.push_back(1.0f);

	//createPyramid(m_VertexVec);
	//createPyramid(m_VertexVec, m_IndicesVec);
	//createColoredPyramid(m_VertexVec, m_IndicesVec);
	createColoredTexturedPyramid(m_VertexVec, m_IndicesVec);

	m_VBO.init();
	m_VBO.fill(m_VertexVec);

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

	//glEnableVertexAttribArray(0);
	//glEnableVertexAttribArray(1);
}

void SimpleGLApp::prepare(const float& _pDeltaTime)
{
	const float Speed = 90.0f;
	//m_RotationAngle += Speed * _pDeltaTime;

	//if(m_RotationAngle > 360.0f)
	//{
	//	m_RotationAngle -= 360.0f;
	//}

	m_RotTimer -= _pDeltaTime;
	if(m_RotTimer > 1)
	{
		float vx, vy, vz;
		float len = 0;
		while(len < 0.001)
		{
			vx = std::rand() % 1000 / 1000.0f; vy = std::rand() % 1000 / 1000.0f; vz = std::rand() % 1000 / 1000.0f;
			len = std::sqrt(vx * vx + vy * vy + vz * vz);	
		}
		
		m_Axisx = vx / len;
		m_Axisy = vy / len;
		m_Axisz = vz / len;

		m_RotTimer = 0.0f;
	}

	glRotatef(Speed * _pDeltaTime, m_Axisx, m_Axisy, m_Axisz);

	glGetFloatv(GL_MODELVIEW_MATRIX, m_ModelViewMat);
	glGetFloatv(GL_PROJECTION_MATRIX, m_ProjectionMat);

	m_ShaderProgram->sendUniformMatrix4fv("modelview_matrix", m_ModelViewMat);
	m_ShaderProgram->sendUniformMatrix4fv("projection_matrix", m_ProjectionMat);
}

void SimpleGLApp::render()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glLoadIdentity();

	//glScalef(0.3f, 0.3f, 1.0f);
	//glScalef(1.f, 0.3f, 1.0f);
	glRotatef(m_RotationAngle, 0.0f, 1.0f, 1.0f);
	//glRotatef(180.0, 0.0f, 1.0f, 0.0f);
	//glRotatef(45, 0.0f, 0.0f, 1.0f);
	//glTranslatef(0.3, 0, 0);
	//glRotatef(45, 0.0f, 0.0f, 1.0f);
	//glTranslatef(0.3, 0, 0);
	//glScalef(0.3f, 0.3f, 1.0f);

	glcVertexArray vertArray;
	glColor3f(0, 1, 0);
	//vertArray.renderVertexArray(m_VertexVec);
	//vertArray.renderVertexColorArray(m_VertexVec, m_ColorsVec);
	//vertArray.renderVertexIndexArray(m_VertexVec, m_IndicesVec);
	//vertArray.renderVertexColorIndexArray(m_VertexVec, m_ColorsVec, m_IndicesVec);
	//m_VBO.render();
	//m_VBO.renderIndexed(m_IndicesVec);
	//m_VBO.renderColoredIndexed(m_IndicesVec);
	//m_VBO.renderShaderedColoredIndexed(m_IndicesVec);
	m_Texture.use();
	m_VBO.renderShaderedTexturedIndexed(m_IndicesVec);

	// glBegin(GL_TRIANGLES);
	// 	glColor3f(1.0f, 0.0f, 0.0f);	glVertex3f(-0.5f, -0.5f, -2.0f);
	// 	glColor3f(1.0f, 1.0f, 0.0f);	glVertex3f( 0.5f, -0.5f, -2.0f);
	// 	glColor3f(0.0f, 0.0f, 1.0f);	glVertex3f( 0.0f,  0.5f, -2.0f);
	// glEnd();
}

void SimpleGLApp::shutdown()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	m_VBO.deinit();
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