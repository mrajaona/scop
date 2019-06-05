#include "depth_shader.h"

static int		vertex_shader(t_shader *shader)
{
	const char *vertex_source = R"glsl(
		#version 330 core

		// Input vertex data, different for all executions of this shader.
		layout(location = 0) in vec3 vertexPosition_modelspace;

		// Values that stay constant for the whole mesh.
		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 proj;

		void main()
		{
			gl_Position =  model * view * proj * vec4(vertexPosition_modelspace, 1);
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
		#version 330 core

		// Ouput data
		layout(location = 0) out float fragmentdepth;

		void main()
		{
			// Not really needed, OpenGL does it anyway
			fragmentdepth = gl_FragCoord.z;
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

int				depth_shader_init(t_shader *shader)
{
	shader->program = glCreateProgram();
	if (!vertex_shader(shader))
		return (0);
	if (!fragment_shader(shader))
		return (0);
	// glBindFragDataLocation(shader->program, 0, "outColor");
	glLinkProgram(shader->program);
	glUseProgram(shader->program);
	return (1);
}
