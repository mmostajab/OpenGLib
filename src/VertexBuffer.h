#ifndef __GLC_VERTEX_BUFFER__
#define __GLC_VERTEX_BUFFER__

#include <GL/gl.h>
#include <GL/glu.h>

/**
 * Renders an array of vertices on the GPU Memory on the screen.
 * Initialization and Deinitialization IS NECESSARY!!!
 */
class glcVertexBuffer
{
private:
	GLuint m_BufferID;

public:
	glcVertexBuffer();

	void init();

	void fill(const GLvoid* _pData, const GLsizeiptr& _pDataSize);
	void render();

	void deinit();

	~glcVertexBuffer();
};

#endif