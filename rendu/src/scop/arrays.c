/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:33:49 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:33:49 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrays.h"

/*
** link points in order
** indices
*/

void			ibo(GLuint *ibo, const GLuint *elements, size_t size)
{
	glGenBuffers(1, ibo); // generate
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibo); // make active
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * size, elements,
		GL_STATIC_DRAW);
}

void			vao(GLuint *vao)
{
	glGenVertexArrays(1, vao); // generate
	glBindVertexArray(*vao); // make active
}

/*
** place all points in space
** pos		tex
** x y z	u v
*/

void			vbo(GLuint *vbo, const float *vertices, size_t size)
{
	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW); // copy the vertex data
}
