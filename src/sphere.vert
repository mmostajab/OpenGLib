uniform mat4 projection_matrix;
uniform mat4 modelview_matrix;

in vec3 a_Vertex;
in vec2 a_TexCoord;
in vec3 a_Normal;

#ifdef SIMPLE_TEXTURING
	out vec2 texCoord;
	out vec3 normal;
#endif

#ifdef SPHERICAL_MAPPING
  out vec3 normal;
  out vec3 view;
#endif

#ifdef CUBE_MAPPING
	uniform vec3 camera_position;
	out vec3 normal;
	out vec3 texCoord0;
	out vec3 view;
#endif

void main(void)
{
#ifdef SIMPLE_TEXTURING
	vec4 pos = modelview_matrix * vec4(a_Vertex, 1.0f);
	gl_Position = projection_matrix * pos;
	texCoord = a_TexCoord;
	normal = a_Normal;
#endif

#ifdef SPHERICAL_MAPPING
  vec4 pos = modelview_matrix * vec4(a_Vertex, 1.0);	
  gl_Position = projection_matrix * pos;
  normal = mat3(modelview_matrix) * a_Normal;
  view = pos.xyz;
#endif

#ifdef CUBE_MAPPING
	vec4 pos = modelview_matrix * vec4(a_Vertex, 1.0);	
	gl_Position = projection_matrix * pos;

	//normal =  a_Normal;
	normal =  mat3(modelview_matrix) * a_Normal;

	//vec3 view = a_Vertex - camera_position.xyz;
	//texCoord0 = -reflect(view, a_Normal);
	view = pos.xyz;
	texCoord0 = -reflect(view, a_Normal);
	//texCoord0 = vec3(a_TexCoord.x, a_TexCoord.y, 0);
	
#endif
}