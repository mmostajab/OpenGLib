#ifdef SIMPLE_TEXTURING
	in vec3 normal;
	in vec2 texCoord;
	uniform sampler2D texture0;
#endif

#ifdef CUBE_MAPPING
	in vec3 texCoord0;
	uniform samplerCube texture0;
#endif

out vec4 outColor;

void main(void)
{
#ifdef SIMPLE_TEXTURING
	outColor = texture(texture0, texCoord);
#endif

#ifdef CUBE_MAPPING
	// outColor = vec4(0.5, 0.5, 0.5, 0.5) + texture(texture0, texCoord0);
	outColor = texture(texture0, texCoord0);
	// outColor = vec4(texCoord0, 1);
#endif
}