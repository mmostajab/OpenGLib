#include "VertexBuffer.h"

#include <stdio.h>

glcVertexBuffer::glcVertexBuffer(): m_BufferID(-1), m_nVertices(0)
{
}

void glcVertexBuffer::init()
{
	glGenBuffers(1, &m_BufferID);
}

void glcVertexBuffer::fill(const std::vector<float>& _pDataVec, GLenum _pUsage)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);	// bind the buffer to the pipeline (only one can be bound to the pipeline)
	glBufferData(GL_ARRAY_BUFFER, _pDataVec.size() * sizeof(float), &_pDataVec[0], _pUsage);
	glBindBuffer(GL_ARRAY_BUFFER, 0);			// unbind any currently bound buffer

	m_nVertices = _pDataVec.size() / 3;
}

void glcVertexBuffer::render()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);	// bind the buffer to the pipeline (only one can be bound to the pipeline)
	glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
	glDrawArrays(GL_TRIANGLES, 0, m_nVertices);
	glBindBuffer(GL_ARRAY_BUFFER, 0);			// unbind any currently bound buffer	
	glDisableClientState(GL_VERTEX_ARRAY);
}

void glcVertexBuffer::deinit()
{
	glDeleteBuffers(1, &m_BufferID);
}

glcVertexBuffer::~glcVertexBuffer()
{
	
}