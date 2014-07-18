#include "SimpleGLApp.h"

SimpleGLApp::SimpleGLApp(const int& _pWidth, const int& _pHeight): GLApp(_pWidth, _pHeight)
{
}

void SimpleGLApp::init()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);

	b_Initialized = true;
}

void SimpleGLApp::prepare(const float& _pDeltaTime)
{
	const float Speed = 15.0f;
	m_RotationAngle += Speed * _pDeltaTime;

	if(m_RotationAngle > 360.0f)
	{
		m_RotationAngle -= 360.0f;
	}
}

void SimpleGLApp::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(m_RotationAngle, 0.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);	glVertex3f(-0.5f, -0.5f, -2.0f);
		glColor3f(1.0f, 1.0f, 0.0f);	glVertex3f( 0.5f, -0.5f, -2.0f);
		glColor3f(0.0f, 0.0f, 1.0f);	glVertex3f( 0.0f,  0.5f, -2.0f);
	glEnd();
}

void SimpleGLApp::shutdown()
{

}

void SimpleGLApp::onResize(const int& _pWidth, const int& _pHeight)
{
	m_Width = _pWidth;	m_Height = _pHeight;
	glViewport(0, 0, m_Width, m_Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, static_cast<float>(m_Width) / static_cast<float>(m_Height), 1.0f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

SimpleGLApp::~SimpleGLApp()
{
}