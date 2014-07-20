#ifndef __GL_APP__
#define __GL_APP__

#include <GL/gl.h>
#include <GL/glu.h>

class GLApp
{
protected:
	bool b_Initialized;
	int m_Width, m_Height;

public:
	GLApp(const int& _pWidth, const int& _pHeight);

	virtual void init();
	virtual void prepare(const float& _pDeltaTime) = 0;
	virtual void render();
	virtual void shutdown() = 0;
	virtual void onResize(const int& _pWidth, const int& _pHeight);

	virtual	bool isInitialized();

	~GLApp();
};

#endif