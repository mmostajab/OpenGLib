#include "Sphere.h"

#include <vector>

Sphere3D::Sphere3D(const float& _pRadius, const int& _pSlices, const int& _pStacks, const char* _pTextureFilename):
	m_Radius(_pRadius), m_Slices(_pSlices), m_Stacks(_pStacks), m_TextureFilename(_pTextureFilename)
{
	m_ShaderHeader = "#version 130\n#define SIMPLE_TEXTURING\n";
	m_ShaderPrg = new glcShaderProgram("../src/sphere.vert", "../src/sphere.frag");
	m_TexturePtr = new glcTexture2D(m_TextureFilename.c_str());

	b_Initialized = false;
	b_CubeMapping = false;
}

Sphere3D::Sphere3D(const float& _pRadius, const int& _pSlices, const int& _pStacks):
	m_Radius(_pRadius), m_Slices(_pSlices), m_Stacks(_pStacks)
{
	m_ShaderHeader = "#version 130\n#define CUBE_MAPPING\n";
	m_ShaderPrg = new glcShaderProgram("../src/sphere.vert", "../src/sphere.frag");

	m_CubeTexturePtr = new glcTextureCube();

	b_Initialized = false;
	b_CubeMapping = true;
}

void Sphere3D::init()
{
	m_ShaderPrg->init(m_ShaderHeader);
	m_ShaderPrg->bindAttribute(0, "a_Vertex");
	m_ShaderPrg->bindAttribute(1, "a_TexCoord");
	m_ShaderPrg->bindAttribute(2, "a_Normal");
	m_ShaderPrg->link();

	if(b_CubeMapping)
		m_CubeTexturePtr->init();
	else
		m_TexturePtr->init();

	const float PI = 3.141562f;
	const float PI2overSlices = 2 * PI / m_Slices;
	const float PIoverStacks = PI / m_Stacks;

	std::vector<SphereVert> vertices;
	float phi, thetha, cosPhi, sinPhi;
	float x, y, z;
	float s, t;
	for(int i = 0; i < m_Stacks; i++)
	{
		int begIndx = vertices.size();
		phi = (float)i * PIoverStacks;
		cosPhi = cos(phi);
		sinPhi = sin(phi);
		for(int j = 0; j < m_Slices; j++)
		{
			thetha = (float)j * PI2overSlices;
			x = cos(thetha) * sinPhi * m_Radius;
			y = sin(thetha) * sinPhi * m_Radius;
			z = cosPhi * m_Radius;

			s  = 1.0f - (float)j / (float)m_Slices;
			t  = (float)i / (float)m_Stacks;
			//s = thetha / (2 * PI);
			//t = phi / PI;


			SphereVert v(x, y, z, s, t);
			v.computeNormal();
			vertices.push_back(v);

			float phi2 = (float)(i + 1) / (float)m_Stacks * PI;
			float cosPhi2 = cos(phi2);
			float sinPhi2 = sin(phi2);
			x = cos(thetha) * sinPhi2 * m_Radius;
			y = sin(thetha) * sinPhi2 * m_Radius;
			z = cosPhi2 * m_Radius;

			s = 1.0f - (float)j / (float)m_Slices;
			t = (float)(i + 1) / (float)m_Stacks;
			//s = thetha / (2 * PI);
			//t = phi2 / PI;

			SphereVert v2(x, y, z, s, t);
			v2.computeNormal();
			vertices.push_back(v2);
		}

		vertices.push_back(vertices[begIndx]);
		vertices.push_back(vertices[begIndx+1]);
	}

	glGenBuffers(1, &m_BufferId);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(SphereVert), &vertices[0], GL_STATIC_DRAW);

	b_Initialized = true;
}

void Sphere3D::render()
{
	glPushMatrix();
	//glEnable(GL_CULL_FACE);

	static float modelViewMat[16];
	static float projectionMat[16];

	glGetFloatv(GL_MODELVIEW_MATRIX, modelViewMat);
	glGetFloatv(GL_PROJECTION_MATRIX, projectionMat);

	m_ShaderPrg->use();
	m_ShaderPrg->sendUniformMatrix4fv("modelview_matrix", modelViewMat);
	m_ShaderPrg->sendUniformMatrix4fv("projection_matrix", projectionMat);
	m_ShaderPrg->sendUniform("texture0", 0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	unsigned int stride = sizeof(SphereVert);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
	glVertexAttribPointer((GLint)0, 3, GL_FLOAT, GL_FALSE, stride, (char*)0);
	glVertexAttribPointer((GLint)1, 2, GL_FLOAT, GL_FALSE, stride, ((char*)0) + 3 * sizeof(float));
	glVertexAttribPointer((GLint)2, 3, GL_FLOAT, GL_FALSE, stride, ((char*)0) + 5 * sizeof(float));

	int nVerticesPerStrip = 2 * (m_Slices + 1);
	int start = 0;
	for(int i = 0; i < m_Stacks; i++)
	{
		glDrawArrays(GL_TRIANGLE_STRIP, start, 2 * (m_Slices + 1));
		start += nVerticesPerStrip;
	}

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glPopMatrix();
}

void Sphere3D::deinit()
{
	
}

Sphere3D::~Sphere3D()
{

}