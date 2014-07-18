#ifndef __GL_WINDOW_GLFW__
#define __GL_WINDOW_GLFW__

#include "GLWindow.h"

class GLWindow_GLFW
{
private:

public:
	GLWindow_GLFW(const char* _pWndName);

	void init(const int& w, const int& h);

	~GLWindow_GLFW();
};

#endif