#ifndef __GL_WINDOW__
#define __GL_WINDOW__

class GLWindow
{
private:

public:
	GLWindow();

	void init(const int& w, const int& h) = 0;

	~GLWindow();
};

#endif