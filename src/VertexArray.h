#ifndef __GLC_Vertex_Array__
#define __GLC_Vertex_Array__

#include <GL/gl.h>
#include <GL/glu.h>

#include <vector>

class glcVertexArray
{
public:
	glcVertexArray();

	void renderVertexArray(const std::vector<float>& _pVec);
	void renderVertexColorArray(const std::vector<float>& _pVec, const std::vector<float>& _pColors);
	void renderVertexIndexArray(const std::vector<float>& _pVec, const std::vector<int>& _pIndices);
	void renderVertexColorIndexArray(const std::vector<float>& _pVec, const std::vector<float>& _pColors, const std::vector<int>& _pIndices);

	~glcVertexArray();
};

#endif