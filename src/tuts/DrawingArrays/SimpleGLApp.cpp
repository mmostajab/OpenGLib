#include "SimpleGLApp.h"

#include "VertexArray.h"

SimpleGLApp::SimpleGLApp(const int& _pWidth, const int& _pHeight): GLApp(_pWidth, _pHeight)
{
}

void SimpleGLApp::init()
{
	GLApp::init();

	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	m_VertexVec.push_back(-0.3f);
	m_VertexVec.push_back(-0.3f);
	m_VertexVec.push_back(-1.0f);

	m_ColorsVec.push_back(0.0f);
	m_ColorsVec.push_back(0.0f);
	m_ColorsVec.push_back(0.0f);

	m_VertexVec.push_back(-0.3f);
	m_VertexVec.push_back( 0.3f);
	m_VertexVec.push_back(-1.0f);

	m_ColorsVec.push_back(1.0f);
	m_ColorsVec.push_back(0.0f);
	m_ColorsVec.push_back(0.0f);

	m_VertexVec.push_back( 0.3f);
	m_VertexVec.push_back(-0.3f);
	m_VertexVec.push_back(-1.0f);

	m_ColorsVec.push_back(0.0f);
	m_ColorsVec.push_back(1.0f);
	m_ColorsVec.push_back(0.0f);

	m_VertexVec.push_back( 0.3f);
	m_VertexVec.push_back( 0.3f);
	m_VertexVec.push_back(-1.0f);

	m_ColorsVec.push_back(0.0f);
	m_ColorsVec.push_back(0.0f);
	m_ColorsVec.push_back(1.0f);

	m_IndicesVec.push_back(0);
	m_IndicesVec.push_back(1);
	m_IndicesVec.push_back(3);

	m_IndicesVec.push_back(0);
	m_IndicesVec.push_back(2);
	m_IndicesVec.push_back(3);

	// m_IndicesVec.push_back(0 * 3 + 0);
	// m_IndicesVec.push_back(0 * 3 + 1);
	// m_IndicesVec.push_back(0 * 3 + 2);

	// m_IndicesVec.push_back(1 * 3 + 0);
	// m_IndicesVec.push_back(1 * 3 + 1);
	// m_IndicesVec.push_back(1 * 3 + 2);

	// m_IndicesVec.push_back(3 * 3 + 0);
	// m_IndicesVec.push_back(3 * 3 + 1);
	// m_IndicesVec.push_back(3 * 3 + 2);

	// m_IndicesVec.push_back(1 * 3 + 0);
	// m_IndicesVec.push_back(1 * 3 + 1);
	// m_IndicesVec.push_back(1 * 3 + 2);

	// m_IndicesVec.push_back(2 * 3 + 0);
	// m_IndicesVec.push_back(2 * 3 + 1);
	// m_IndicesVec.push_back(2 * 3 + 2);

	// m_IndicesVec.push_back(3 * 3 + 0);
	// m_IndicesVec.push_back(3 * 3 + 1);
	// m_IndicesVec.push_back(3 * 3 + 2);

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
}

void SimpleGLApp::prepare(const float& _pDeltaTime)
{
	const float Speed = 45.0f;
	m_RotationAngle += Speed * _pDeltaTime;

	if(m_RotationAngle > 360.0f)
	{
		m_RotationAngle -= 360.0f;
	}
}

void SimpleGLApp::render()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(m_RotationAngle, 0.0f, 0.0f, 1.0f);

	glcVertexArray vertArray;
	glColor3f(0, 1, 0);
	//vertArray.renderVertexArray(m_VertexVec);
	//vertArray.renderVertexColorArray(m_VertexVec, m_ColorsVec);
	//vertArray.renderVertexIndexArray(m_VertexVec, m_IndicesVec);
	vertArray.renderVertexColorIndexArray(m_VertexVec, m_ColorsVec, m_IndicesVec);

	// glBegin(GL_TRIANGLES);
	// 	glColor3f(1.0f, 0.0f, 0.0f);	glVertex3f(-0.5f, -0.5f, -2.0f);
	// 	glColor3f(1.0f, 1.0f, 0.0f);	glVertex3f( 0.5f, -0.5f, -2.0f);
	// 	glColor3f(0.0f, 0.0f, 1.0f);	glVertex3f( 0.0f,  0.5f, -2.0f);
	// glEnd();
}

void SimpleGLApp::shutdown()
{

}

void SimpleGLApp::onResize(const int& _pWidth, const int& _pHeight)
{
	GLApp::onResize(_pWidth, _pHeight);
}

SimpleGLApp::~SimpleGLApp()
{
}