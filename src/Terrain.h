#ifndef __TERRAIN_3D_H__
#define __TERRAIN_3D_H__

#include <GL/glew.h>
#include <vector>

struct TerrainVertex
{
	float x, y, z;

	TerrainVertex(const float& _pX = 0.0f, const float& _pY = 0.0f, const float& _pZ = 0.0f): x(_pX), y(_pY), z(_pZ)
	{
	}
};

struct TerrainColor
{
	float r, g, b;

	TerrainColor(const float& _pR = 0.0f, const float& _pG = 0.0f, const float& _pB = 0.0f): r(_pR), g(_pG), b(_pB)
	{
	}
};

struct TerrainTexCoord
{
	float s, t;

	TerrainTexCoord(const float& _pS = 0.0f, const float& _pT = 0.0f): s(_pS), t(_pT)
	{
	}
};

class Terrain3D
{
private:
	int m_Width, m_Height;

	GLuint m_VBid, m_IBid, m_ColorId, m_TexCoordId;		// Vertex Buffer ID, Index Buffer ID, ...
	std::vector<TerrainVertex> m_Vertices;
	std::vector<TerrainColor>  m_Colors;
	std::vector<TerrainTexCoord> m_TexCoords;
	std::vector<int> m_Indices;

	bool b_Initialized;

public:
	Terrain3D();

	void init(const char* _pRawFilename, const int& _pWidth, const int& _pHeight = -1);

	void render();

	void deinit();

	~Terrain3D();

private:
	void generateVertices(const std::vector<float>& _pHeightMap);
	void generateIndices();
	void generateTexCoords();
};

#endif