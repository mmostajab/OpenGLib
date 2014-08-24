#include "Box.h"

#include <vector>

Box3D::Box3D(const float& _pWidth, const char* _pTextureFilename):
	m_Width(_pWidth), m_TextureFilename(_pTextureFilename), m_X(0.0f), m_Y(0.0f), m_Z(0.0f), m_RotDeg(0.0f)
{
	m_ShaderHeader = "#version 130\n#define SIMPLE_TEXTURING\n";
	m_ShaderPrg = new glcShaderProgram("../src/sphere.vert", "../src/sphere.frag");
	m_TexturePtr = new glcTexture2D(m_TextureFilename.c_str());

	b_Initialized = false;
	b_CubeMapping = false;
}

Box3D::Box3D(const float& _pWidth):
	m_Width(_pWidth), m_X(0.0f), m_Y(0.0f), m_Z(0.0f)
{
	m_ShaderHeader = "#version 130\n#define CUBE_MAPPING\n";
	m_ShaderPrg = new glcShaderProgram("../src/sphere.vert", "../src/sphere.frag");

	m_CubeTexturePtr = new glcTextureCube();

	b_Initialized = false;
	b_CubeMapping = true;
}

void Box3D::init(const float& _pX, const float& _pY, const float& _pZ)
{
	m_ShaderPrg->init(m_ShaderHeader);
	m_ShaderPrg->bindAttribute(0, "a_Vertex");
	m_ShaderPrg->bindAttribute(1, "a_TexCoord");
	m_ShaderPrg->bindAttribute(2, "a_Normal");
	m_ShaderPrg->link();

	if(b_CubeMapping)
		m_CubeTexturePtr->init(10, 10, 10);
	else
		m_TexturePtr->init();

	std::vector<BoxVert> vertices;
	
	vertices.push_back(BoxVert(-m_Width / 2.0f,  m_Width / 2.0f, -m_Width / 2.0f, 0, 1, 0, 0, 1));
	vertices.push_back(BoxVert(-m_Width / 2.0f, -m_Width / 2.0f, -m_Width / 2.0f, 0, 0, 0, 0, 1));
	vertices.push_back(BoxVert( m_Width / 2.0f,  m_Width / 2.0f, -m_Width / 2.0f, 1, 1, 0, 0, 1));
	vertices.push_back(BoxVert( m_Width / 2.0f, -m_Width / 2.0f, -m_Width / 2.0f, 1, 0, 0, 0, 1));
	
	vertices.push_back(BoxVert(-m_Width / 2.0f,  m_Width / 2.0f,  m_Width / 2.0f, 1, 1, 0, 0, -1));
	vertices.push_back(BoxVert(-m_Width / 2.0f, -m_Width / 2.0f,  m_Width / 2.0f, 1, 0, 0, 0, -1));
	vertices.push_back(BoxVert( m_Width / 2.0f,  m_Width / 2.0f,  m_Width / 2.0f, 0, 1, 0, 0, -1));
	vertices.push_back(BoxVert( m_Width / 2.0f, -m_Width / 2.0f,  m_Width / 2.0f, 0, 0, 0, 0, -1));

	vertices.push_back(BoxVert(-m_Width / 2.0f, -m_Width / 2.0f,  m_Width / 2.0f, 0, 0, 0, 1, 0));
	vertices.push_back(BoxVert(-m_Width / 2.0f, -m_Width / 2.0f, -m_Width / 2.0f, 0, 1, 0, 1, 0));
	vertices.push_back(BoxVert( m_Width / 2.0f, -m_Width / 2.0f,  m_Width / 2.0f, 1, 0, 0, 1, 0));
	vertices.push_back(BoxVert( m_Width / 2.0f, -m_Width / 2.0f, -m_Width / 2.0f, 1, 1, 0, 1, 0));
	
	vertices.push_back(BoxVert(-m_Width / 2.0f,  m_Width / 2.0f,  m_Width / 2.0f, 1, 0, 0, -1, 0));
	vertices.push_back(BoxVert(-m_Width / 2.0f,  m_Width / 2.0f, -m_Width / 2.0f, 1, 1, 0, -1, 0));
	vertices.push_back(BoxVert( m_Width / 2.0f,  m_Width / 2.0f,  m_Width / 2.0f, 0, 0, 0, -1, 0));
	vertices.push_back(BoxVert( m_Width / 2.0f,  m_Width / 2.0f, -m_Width / 2.0f, 0, 1, 0, -1, 0));
	
	vertices.push_back(BoxVert(-m_Width / 2.0f, -m_Width / 2.0f,  m_Width / 2.0f, 0, 0, -1, 0, 0));
	vertices.push_back(BoxVert(-m_Width / 2.0f, -m_Width / 2.0f, -m_Width / 2.0f, 1, 0, -1, 0, 0));
	vertices.push_back(BoxVert(-m_Width / 2.0f,  m_Width / 2.0f,  m_Width / 2.0f, 0, 1, -1, 0, 0));
	vertices.push_back(BoxVert(-m_Width / 2.0f,  m_Width / 2.0f, -m_Width / 2.0f, 1, 1, -1, 0, 0));
	
	vertices.push_back(BoxVert( m_Width / 2.0f, -m_Width / 2.0f,  m_Width / 2.0f, 1, 0,  1, 0, 0));
	vertices.push_back(BoxVert( m_Width / 2.0f, -m_Width / 2.0f, -m_Width / 2.0f, 0, 0,  1, 0, 0));
	vertices.push_back(BoxVert( m_Width / 2.0f,  m_Width / 2.0f,  m_Width / 2.0f, 1, 1,  1, 0, 0));
	vertices.push_back(BoxVert( m_Width / 2.0f,  m_Width / 2.0f, -m_Width / 2.0f, 0, 1,  1, 0, 0));

	glGenBuffers(1, &m_BufferId);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(BoxVert), &vertices[0], GL_STATIC_DRAW);

	m_X = _pX;
	m_Y = _pY;
	m_Z = _pZ;
	
	b_Initialized = true;
}

void Box3D::render()
{
	glPushMatrix();
	//glEnable(GL_CULL_FACE);
	
	glMatrixMode(GL_MODELVIEW_MATRIX);
 	//glLoadIdentity();
 	glTranslatef(m_X, m_Y, m_Z);
	//glRotatef(m_RotDeg, 1, 0, 0);
	m_RotDeg += 0.3;
 
 	static float modelViewMat[16];
 	static float projectionMat[16];
 
 	glGetFloatv(GL_MODELVIEW_MATRIX, modelViewMat);
 	glGetFloatv(GL_PROJECTION_MATRIX, projectionMat);
 
 	m_ShaderPrg->use();
 	m_ShaderPrg->sendUniformMatrix4fv("modelview_matrix", modelViewMat);
 	m_ShaderPrg->sendUniformMatrix4fv("projection_matrix", projectionMat);
 	m_ShaderPrg->sendUniform("texture0", 0);
// 
 	if(b_CubeMapping)
 	{
 	  
 		m_ShaderPrg->sendUniform3fv("camera_position", 0.0f, 0.0f, 0.0f);
 		m_CubeTexturePtr->use();
 	}
 	else
 		m_TexturePtr->use();
 
 	glEnableVertexAttribArray(0);
 	glEnableVertexAttribArray(1);
 	glEnableVertexAttribArray(2);
 
 	unsigned int stride = sizeof(BoxVert);
 	glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
 	glVertexAttribPointer((GLint)0, 3, GL_FLOAT, GL_FALSE, stride, (char*)0);
 	glVertexAttribPointer((GLint)1, 2, GL_FLOAT, GL_FALSE, stride, ((char*)0) + 3 * sizeof(float));
 	glVertexAttribPointer((GLint)2, 3, GL_FLOAT, GL_FALSE, stride, ((char*)0) + 5 * sizeof(float));
 
 	int nVerticesPerSide = 4;
 	int start = 0;
 	for(int i = 0; i < 6; i++)
 	{
 		glDrawArrays(GL_TRIANGLE_STRIP, start, 4);
 		start += nVerticesPerSide;
 	}
 
 	glDisableVertexAttribArray(0);
 	glDisableVertexAttribArray(1);
 	glDisableVertexAttribArray(2);

	glPopMatrix();
}

void Box3D::deinit()
{
	
}

void Box3D::setPosition(const float& _pX, const float& _pY, const float& _pZ)
{
  m_X = _pX;
  m_Y = _pY;
  m_Z = _pZ;
  
  if(b_CubeMapping)
    m_CubeTexturePtr->setPosition(m_X, m_Y, m_Z);
}

glcTextureCube* Box3D::getTextureCubePtr()
{
  return m_CubeTexturePtr;
}

Box3D::~Box3D()
{

}