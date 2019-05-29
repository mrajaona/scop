#include "light_shader.h"

static int		shader_status(const GLuint shader)
{
	GLint status;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		fprintf(stderr, "shader init error\n");
		fflush(stderr);
		return (0);
	}
	return (1);
}

static int		vertex_shader(t_shader *shader)
{
	const char *vertex_source = R"glsl(
		#version 150 core

		in vec3 position;

		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 proj;

		void main()
		{
			gl_Position = proj * view * model * vec4(position, 1.0);
		}
	)glsl";

	shader->vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader->vertex, 1, &vertex_source, NULL);
	glCompileShader(shader->vertex);
	if (!shader_status(shader->vertex))
		return (0);
	glAttachShader(shader->program, shader->vertex);
	return (1);
}

static int		fragment_shader(t_shader *shader)
{
	const char *fragment_source = R"glsl(
		#version 150 core

		out vec4 outColor;

		uniform sampler2D texScop;

		void main()
		{
			vec4 defaultColor = vec4(1.0, 1.0, 1.0, 0.1);
			outColor = defaultColor;
		}
	)glsl";

	shader->fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader->fragment, 1, &fragment_source, NULL);
	glCompileShader(shader->fragment);
	if (!shader_status(shader->fragment))
		return (0);
	glAttachShader(shader->program, shader->fragment);
	return (1);
}

int				light_shader_init(t_shader *shader)
{
	shader->program = glCreateProgram();
	if (!vertex_shader(shader))
		return (0);
	if (!fragment_shader(shader))
		return (0);
	glBindFragDataLocation(shader->program, 0, "outColor");
	glLinkProgram(shader->program);
	glUseProgram(shader->program);
	return (1);
}
