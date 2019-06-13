#version 330 core

in vec3 ModelPos;
in vec3 Normal;
in vec2 Texcoord;
in vec3 Color;

out vec4 outColor;

uniform sampler2D texScop;

uniform vec3 viewPos;

struct Light {
	vec3 position;
	vec3 color;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Light light;

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

uniform Material material;
uniform float blend;

void main()
{
	vec4 tex = texture(texScop, Texcoord);

	// ambient
	vec3 ambient = material.ambient * light.ambient * light.color;
	
	// diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - ModelPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * material.diffuse * light.diffuse * light.color;
	
	// specular
	vec3 viewDir = normalize(viewPos - ModelPos);
	vec3 reflectDir = reflect(-lightDir, norm);  
	float spec = pow(max(dot(viewDir, reflectDir), 0.0),
		material.shininess);
	vec3 specular = spec * material.specular * light.specular * light.color;  
		
	vec3 result = ambient + diffuse + specular;

	outColor = mix(vec4(Color, 1.0), tex, blend) * vec4(result, 1.0);
}
