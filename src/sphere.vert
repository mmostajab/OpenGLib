uniform mat4 projection_matrix;
uniform mat4 modelview_matrix;

in vec3 a_Vertex;
in vec2 a_TexCoord;
in vec3 a_Normal;

out vec2 texCoord;
out vec3 normal;

void main(void)
{
#ifdef SIMPLE_TEXTURING
	vec4 pos = modelview_matrix * vec4(a_Vertex, 1.0f);
	gl_Position = projection_matrix * pos;
	texCoord = a_TexCoord;
	normal = a_Normal;
#endif

#ifdef CUBE_MAPPING
	vec4 pos = modelview_matrix * vec4(a_Vertex, 1.0f);
	gl_Position = projection_matrix * pos;
	texCoord = a_TexCoord;
	normal = a_Normal;
#endif
}