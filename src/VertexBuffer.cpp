#include "VertexBuffer.h"

glcVertexBuffer::glcVertexBuffer()
{

}

void glcVertexBuffer::init()
{
	glGenBuffers(1, &m_BufferID);

}

void glcVertexBuffer::fill(const GLvoid* _pDataPtr, const GLsizeiptr& _pDataSize, GLenum _pUsage)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);	// bind the buffer to the pipeline (only one can be bound to the pipeline)

	glBufferData(GL_ARRAY_BUFFER, _pDataSize, _pDataPtr, _pUsage);

	glBindBuffer(GL_ARRAY_BUFFER, 0);			// unbind any currently bound buffer
}

void glcVertexBuffer::deinit()
{
	glDeleteBuffers(1, &m_BufferID);
}

glcVertexBuffer::~glcVertexBuffer()
{
	
}