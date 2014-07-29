#include "GLApp.h"

GLApp::GLApp(const int& _pWidth, const int& _pHeight): b_Initialized(false), m_Width(_pWidth), m_Height(_pHeight)
{
}

void GLApp::init()
{
	GLenum err = glewInit();
	if(err != GLEW_OK)
	{
		return;
	}

	glEnable(GL_DEPTH_TEST);

	// set the Class as initialized
	b_Initialized = true;
}

void GLApp::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}

void GLApp::onResize(const int& _pWidth, const int& _pHeight)
{
	m_Width = _pWidth;	m_Height = _pHeight;
	glViewport(0, 0, m_Width, m_Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, static_cast<float>(m_Width) / static_cast<float>(m_Height), 0.01f, 100.0f);

	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -3);
}

bool GLApp::isInitialized()
{
	return b_Initialized;
}

GLApp::~GLApp()
{
}