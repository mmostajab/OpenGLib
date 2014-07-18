#include "GLWindow_GLFW.h"

GLWindow_GLFW::GLWindow_GLFW(const char* _pWndName): GLWindow(_pWndName)
{
	m_WndPtr = 0;
}

void GLWindow_GLFW::init(const int& w, const int& h)
{
	m_Width = w;
	m_Height = h;

	m_WindowPtr = glfwCreateWindow(m_Width, m_Height, m_W)
}