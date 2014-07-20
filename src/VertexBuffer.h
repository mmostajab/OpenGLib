#ifndef __GLC_VERTEX_BUFFER__
#define __GLC_VERTEX_BUFFER__

// #define GL_GLEXT_PROTOTYPES
// #include <GL/gl.h>
// #include <GL/glu.h>
// #include <GL/glx.h>
// #include <GL/glext.h>

#include <GL/glew.h>
#include <vector>

#define BUFFER_OFFSET(i)	((char*)NULL + (i))

/**
 * Renders an array of vertices on the GPU Memory on the screen.
 * Initialization and Deinitialization IS NECESSARY!!!
 */
class glcVertexBuffer
{
private:
	GLuint m_BufferID;
	int m_nVertices;

public:
	glcVertexBuffer();

	void init();

	void fill(const std::vector<float>& _pDataVec, GLenum _pUsage = GL_STATIC_DRAW);
	void render();

	void deinit();

	~glcVertexBuffer();
};

#endif