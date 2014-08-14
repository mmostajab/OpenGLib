#include "Terrain.h"

#include <iostream>
#include <fstream>
#include <string>

Terrain3D::Terrain3D(): b_Initialized(false)
{

}

void Terrain3D::init(const char* _pRawFilename, const int& _pWidth, const int& _pHeight)
{
	m_Width = _pWidth;
	m_Height = _pWidth;
	if(_pHeight != -1)
		m_Height = _pHeight;

	const float HEIGHT_SCALE = 10.0f;
	std::ifstream inFile(_pRawFilename, std::ios::binary);

	if(!inFile.good())
	{
		std::cerr << "File does not exist.\n";
		return;
	}

	std::string stringBuffer(std::istreambuf_iterator<char>(inFile), (std::istreambuf_iterator<char>()));
	if(stringBuffer.size() != static_cast<unsigned int>(m_Width * m_Height))
	{
		std::cerr << "String size does not match.\n";
		return;
	}

	std::vector<float> heights;
	heights.reserve(m_Width * m_Height);
	float value;

	for(int i = 0; i < m_Width * m_Height; i++)
	{
		value = static_cast<float>(((unsigned char*)stringBuffer.c_str())[i]) / 256.0f;
		heights.push_back(HEIGHT_SCALE * value);
		m_Colors.push_back(TerrainColor(value, value, value));
	}

	glGenBuffers(1, &m_ColorId);
	glBindBuffer(GL_ARRAY_BUFFER, m_ColorId);
	glBufferData(GL_ARRAY_BUFFER, m_Colors.size() * sizeof(TerrainColor), &m_Colors[0], GL_STATIC_DRAW);

	generateVertices(heights);
	generateTexCoords();
	generateIndices();

	b_Initialized = true;
}

void Terrain3D::render()
{
	//Bind the vertex array and set the vertex pointer to point at it
    glBindBuffer(GL_ARRAY_BUFFER, m_VBid);
    glVertexAttribPointer((GLint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    //Bind the color array
    glBindBuffer(GL_ARRAY_BUFFER, m_ColorId);
    glVertexAttribPointer((GLint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_TexCoordId);
    glVertexAttribPointer((GLint)2, 2, GL_FLOAT, GL_FALSE, 0, 0);

    //Bind the index array
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBid);

    //Draw the triangles
    glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, 0);
}

void Terrain3D::deinit()
{
	b_Initialized = false;
}

Terrain3D::~Terrain3D()
{
}

void Terrain3D::generateVertices(const std::vector<float>& _pHeightMap)
{
	int indx = 0;
	for(int x = -m_Width / 2; x <= m_Width / 2; x++)
	{
		for(int z = -m_Height / 2; z <= m_Height / 2; z++)
		{
			//std::cout << x << ", " << _pHeightMap[indx] << ", " << z << std::endl;
			m_Vertices.push_back(TerrainVertex(x, _pHeightMap[indx++], z));
		}
	}

	glGenBuffers(1, &m_VBid);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBid);
	glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(TerrainVertex), &m_Vertices[0], GL_STATIC_DRAW);
}

void Terrain3D::generateIndices()
{
	for(int x = 0; x < m_Width - 1; x++)
		for(int z = 0; z < m_Height - 1; z++)
		{
			m_Indices.push_back(x * m_Height + z);
			m_Indices.push_back(x * m_Height + z + 1);
			m_Indices.push_back((x + 1) * m_Height + z + 1);

			m_Indices.push_back((x + 1) * m_Height + z);
			m_Indices.push_back((x + 1) * m_Height + z + 1);
			m_Indices.push_back( x * m_Height + z);

			//std::cout << x * m_Height + z << ", " << x * m_Height + z + 1 << ", " << ((x + 1) * m_Height + z + 1) << std::endl;
		}

	glGenBuffers(1, &m_IBid);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBid);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(int), &m_Indices[0], GL_STATIC_DRAW);
}

void Terrain3D::generateTexCoords()
{
	float s, t;
	for(int x = 0; x < m_Width; x++)
		for(int z = 0; z < m_Height; z++)
		{
			s = (static_cast<float>(x) / static_cast<float>(m_Width)) * 8.0f;
			t = (static_cast<float>(z) / static_cast<float>(m_Height)) * 8.0f;

			//std::cout << s << ", " << t << std::endl;

			m_TexCoords.push_back(TerrainTexCoord(s, t));
		}

	glGenBuffers(1, &m_TexCoordId);
	glBindBuffer(GL_ARRAY_BUFFER, m_TexCoordId);
	glBufferData(GL_ARRAY_BUFFER, m_TexCoords.size() * sizeof(TerrainTexCoord), &m_TexCoords[0], GL_STATIC_DRAW);
}