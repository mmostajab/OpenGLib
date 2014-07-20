#include "VertexArray.h"

glcVertexArray::glcVertexArray()
{

}

void glcVertexArray::renderVertexArray(const std::vector<float>& _pVec)
{
	glPushMatrix();
    // glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, &_pVec[0]);
	glDrawArrays(GL_TRIANGLES, 0, _pVec.size() / 3);
	glDisableClientState(GL_VERTEX_ARRAY);

   // glPopClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
	glPopMatrix();
}

void glcVertexArray::renderVertexColorArray(const std::vector<float>& _pVec, const std::vector<float>& _pColors)
{
	glPushMatrix();
    // glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, &_pVec[0]);
	glColorPointer(3, GL_FLOAT, 0, &_pColors[0]);
	glDrawArrays(GL_TRIANGLES, 0, _pVec.size() / 3);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

// glPopClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
	glPopMatrix();
}

void glcVertexArray::renderVertexIndexArray(const std::vector<float>& _pVec, const std::vector<int>& _pIndices)
{
	glPushMatrix();
    // glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, &_pVec[0]);
	glDrawElements(GL_TRIANGLES, _pIndices.size(), GL_UNSIGNED_INT, &_pIndices[0]);
	glDisableClientState(GL_VERTEX_ARRAY);

   // glPopClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
	glPopMatrix();
}

void glcVertexArray::renderVertexColorIndexArray(const std::vector<float>& _pVec, const std::vector<float>& _pColors, const std::vector<int>& _pIndices)
{
	glPushMatrix();
    // glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, &_pVec[0]);
	glColorPointer(3, GL_FLOAT, 0, &_pColors[0]);
	glDrawElements(GL_TRIANGLES, _pIndices.size(), GL_UNSIGNED_INT, &_pIndices[0]);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

   // glPopClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
	glPopMatrix();
}

glcVertexArray::~glcVertexArray()
{

}
