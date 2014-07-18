#ifndef __GL_WINDOW__
#define __GL_WINDOW__

#include <string>

class GLWindow
{
protected:
	std::string m_WndName;
	int m_Width, m_Height;

public:
	GLWindow(const char* _pWndName);

	void init(const int& w, const int& h) = 0;

	~GLWindow();
};

#endif