#ifdef SIMPLE_TEXTURING
	in vec3 normal;
	in vec2 texCoord;
	uniform sampler2D texture0;
#endif

#ifdef SPHERICAL_MAPPING
  in vec3 normal;
  in vec3 view;
  uniform sampler2D texture0;
#endif

#ifdef CUBE_MAPPING
	in vec3 normal;
	in vec3 view;
	in vec3 texCoord0;
	uniform samplerCube texture0;
#endif

out vec4 outColor;

void main(void)
{
#ifdef SIMPLE_TEXTURING
	outColor = texture(texture0, texCoord);
#endif

#ifdef SPHERICAL_MAPPING
  vec3 r = reflect(normalize(view), normalize(normal)); 
  
  r.z += 1.0f;
  float m = 0.5 * inversesqrt(dot(r, r));
  
  outColor = texture(texture0, r.xy * m);
  

#endif

#ifdef CUBE_MAPPING
	//outColor = vec4(0.5, 0.5, 0.5, 0.5) + texture(texture0, texCoord0);
	//vec3 texCoord = reflect(view, normalize(normal));
	// outColor = texture(texture0, texCoord);
	
	outColor = texture(texture0, texCoord0);
	
	//outColor = vec4((texCoord0.r + 1) / 2.0f, (texCoord0.r + 1) / 2.0f, (texCoord0.r + 1) / 2.0f, 1.0f);
	//outColor = vec4(texCoord0, 1);
#endif
}