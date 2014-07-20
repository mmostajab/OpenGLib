#ifndef __SIMPLE_GL_APP__
#define __SIMPLE_GL_APP__

#include "GLApp.h"
#include <vector>

class SimpleGLApp: public GLApp
{
private:
	float m_RotationAngle;
	std::vector<float> m_VertexVec;
	std::vector<float> m_ColorsVec;
	std::vector<int> m_IndicesVec;

public:
	SimpleGLApp(const int& _pWidth = 640, const int& _pHeight = 480);

	virtual void init();
	virtual void prepare(const float& _pDeltaTime);
	virtual void render();
	virtual void shutdown();
	virtual void onResize(const int& _pWidth, const int& _pHeight);

	~SimpleGLApp();
};

#endif