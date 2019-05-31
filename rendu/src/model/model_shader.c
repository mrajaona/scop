/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.shader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:34:26 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:34:26 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model_shader.h"

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

		// in vec2 texcoord;
		in vec3 position;
		in vec3 normal;

		// out vec2 Texcoord;
		out vec3 Normal;
		out vec3 ModelPos;

		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 proj;

		void main()
		{
			gl_Position = proj * view * model * vec4(position, 1.0);
			ModelPos = vec3(model * vec4(position, 1.0));
			Normal = normal;
			// Texcoord = texcoord;
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

		// in vec2 Texcoord;
		in vec3 Normal;
		in vec3 ModelPos;

		out vec4 outColor;

		uniform sampler2D texScop;

		uniform vec3 lightPos;
		uniform vec3 lightColor;
		uniform vec3 modelColor;

		void main()
		{
			// outColor = texture(texScop, Texcoord);

			float ambient = 0.1;

			vec3 norm = normalize(Normal);
			vec3 potato = vec3(0.0, 0.0, 5.0);
			// vec3 lightDir = normalize(lightPos - ModelPos);
			vec3 lightDir = normalize(potato - ModelPos);

			float diffuse = max(dot(norm, lightDir), 0.0);

			vec3 finalColor = (ambient + diffuse) * lightColor * modelColor;
			outColor = vec4(finalColor, 1.0);
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

int				model_shader_init(t_shader *shader)
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
