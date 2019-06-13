#version 330 core

in vec3 position;
in vec3 normal;
in vec2 texcoord;
in vec3 color;

out vec3 ModelPos;
out vec3 Normal;
out vec2 Texcoord;
out vec3 Color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	gl_Position = proj * view * model * vec4(position, 1.0);
	ModelPos = vec3(model * vec4(position, 1.0));
	Normal = mat3(transpose(inverse(model))) * normal;
	Texcoord = texcoord;
	Color = color;
}
