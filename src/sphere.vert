uniform mat4 projection_matrix;
uniform mat4 modelview_matrix;

in vec3 a_Vertex;
in vec2 a_TexCoord;
in vec3 a_Normal;

#ifdef SIMPLE_TEXTURING
	out vec2 texCoord;
	out vec3 normal;
#endif

#ifdef CUBE_MAPPING
	uniform vec3 camera_position;
	out vec3 texCoord0;
#endif

void main(void)
{
#ifdef SIMPLE_TEXTURING
	vec4 pos = modelview_matrix * vec4(a_Vertex, 1.0f);
	gl_Position = projection_matrix * pos;
	texCoord = a_TexCoord;
	normal = a_Normal;
#endif

#ifdef CUBE_MAPPING
	vec4 pos = modelview_matrix * vec4(a_Vertex, 1.0);	
	gl_Position = projection_matrix * pos;

	vec3 normal = mat3(modelview_matrix) * a_Normal;

	vec3 view = pos.xyz - camera_position.xyz;
	texCoord0 = -reflect(view, normal);
#endif
}