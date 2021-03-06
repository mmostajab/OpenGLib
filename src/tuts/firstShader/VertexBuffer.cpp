#include "VertexBuffer.h"

#include <iostream>
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

void glcVertexBuffer::renderIndexed(const std::vector<int>& _pIndexVec)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);	// bind the buffer to the pipeline (only one can be bound to the pipeline)
	glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
	glDrawElements(GL_TRIANGLES, _pIndexVec.size(), GL_UNSIGNED_INT, &_pIndexVec[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);			// unbind any currently bound buffer	
	glDisableClientState(GL_VERTEX_ARRAY);	
}

void glcVertexBuffer::renderColoredIndexed(const std::vector<int>& _pIndexVec)
{
	//glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);	// bind the buffer to the pipeline (only one can be bound to the pipeline)

	// stride is the size of one element of the vertex data information.
	size_t stride = 6 * sizeof(float);
	//glVertexPointer(3, GL_FLOAT, stride, BUFFER_OFFSET(0));
	//glColorPointer(3, GL_FLOAT, stride, BUFFER_OFFSET(3 * sizeof(float)));

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, BUFFER_OFFSET(0));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, BUFFER_OFFSET(3 * sizeof(float)));
	// glVertexAttribPointer((GLint)1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(BLUE_OFFSET));

	glDrawElements(GL_TRIANGLES, _pIndexVec.size(), GL_UNSIGNED_INT, &_pIndexVec[0]);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);			// unbind any currently bound buffer	
	//glDisableClientState(GL_COLOR_ARRAY);
	//glDisableClientState(GL_VERTEX_ARRAY);	

	//glDisableVertexAttribArray(1);
	//glDisableVertexAttribArray(0);
}

void glcVertexBuffer::deinit()
{
	glDeleteBuffers(1, &m_BufferID);
}

glcVertexBuffer::~glcVertexBuffer()
{
	
}