in vec3 normal;
in vec2 texCoord;
uniform sampler2D texture0;

out vec4 outColor;

void main(void)
{
#ifdef SIMPLE_TEXTURING
	outColor = texture(texture0, texCoord);
#endif

#ifdef CUBE_MAPPING
	outColor = vec4(normal, 1.0);
#endif
}