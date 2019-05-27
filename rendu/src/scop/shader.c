/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:34:26 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:34:26 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader.h"

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

		in vec2 texcoord;
		in vec3 position;

		out vec2 Texcoord;

		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 proj;

		void main()
		{
			Texcoord = texcoord;
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

		in vec3 Color;
		in vec2 Texcoord;
		out vec4 outColor;

		uniform sampler2D texScop;

		void main()
		{
			outColor = texture(texScop, Texcoord);
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

/*
** pos_attrib = x, y, z
** tex_attrib = u, v
*/

static void		vertex_attribute_array(const GLuint shader_program)
{
	GLint pos_attrib;
	// GLint tex_attrib;

	pos_attrib = glGetAttribLocation(shader_program, "position");
	glEnableVertexAttribArray(pos_attrib);
	glVertexAttribPointer(pos_attrib, 3, GL_FLOAT, GL_FALSE,
		N_DATA_PER_VERTICE * sizeof(float), 0);
	/*
	tex_attrib = glGetAttribLocation(shader_program, "texcoord");
	glEnableVertexAttribArray(tex_attrib);
	glVertexAttribPointer(tex_attrib, 2, GL_FLOAT, GL_FALSE,
		5 * sizeof(float), (void *)(3 * sizeof(float)));
	*/
}

int				shader_init(t_shader *shader)
{
	shader->program = glCreateProgram();
	if (!vertex_shader(shader))
		return (0);
	if (!fragment_shader(shader))
		return (0);
	glBindFragDataLocation(shader->program, 0, "outColor");
	glLinkProgram(shader->program);
	glUseProgram(shader->program);
	vertex_attribute_array(shader->program);
	return (1);
}
