/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_model_attribs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:56:10 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/13 10:56:11 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_model_attribs.h"

static void	attrib_position(const GLuint program)
{
	GLint	attrib;

	attrib = glGetAttribLocation(program, "position");
	glVertexAttribPointer(attrib,
		3, GL_FLOAT, GL_FALSE,
		NDATA * sizeof(float),
		0);
	glEnableVertexAttribArray(attrib);
}

static void	attrib_texture(const GLuint program)
{
	GLint attrib;

	attrib = glGetAttribLocation(program, "normal");
	glVertexAttribPointer(attrib, 3, GL_FLOAT, GL_FALSE,
		NDATA * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(attrib);
	attrib = glGetAttribLocation(program, "texcoord");
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE,
		NDATA * sizeof(float), (void *)(6 * sizeof(float)));
	glEnableVertexAttribArray(attrib);
}

static void	attrib_color(const GLuint program)
{
	GLint	attrib;

	attrib = glGetAttribLocation(program, "color");
	glVertexAttribPointer(attrib, 3, GL_FLOAT, GL_FALSE,
		NDATA * sizeof(float), (void *)(8 * sizeof(float)));
	glEnableVertexAttribArray(attrib);
}

static void	attrib_light(const GLuint program, const t_model *model)
{
	GLint	attrib;

	attrib = glGetUniformLocation(program,
		"material.ambient");
	glUniform3fv(attrib, 1, model->material.ka);
	attrib = glGetUniformLocation(program,
		"material.diffuse");
	glUniform3fv(attrib, 1, model->material.kd);
	attrib = glGetUniformLocation(program,
		"material.specular");
	glUniform3fv(attrib, 1, model->material.ks);
	attrib = glGetUniformLocation(program,
		"material.shininess");
	glUniform1f(attrib, model->material.ns);
}

void		set_attribs(const GLuint program, const t_model *model)
{
	attrib_position(program);
	attrib_texture(program);
	attrib_color(program);
	attrib_light(program, model);
}
