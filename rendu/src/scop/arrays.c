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

void			ebo(GLuint *ebo, const GLuint *elements, size_t size)
{
	glGenBuffers(1, ebo); // generate
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo); // make active
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

/*
	// 0123
	+0.5f, -0.5f, -0.5f,	1.0f, 1.0f, // 0
	+0.5f, -0.5f, +0.5f,	1.0f, 0.0f, // 1
	-0.5f, -0.5f, +0.5f,	0.0f, 0.0f, // 2

	-0.5f, -0.5f, +0.5f,	0.0f, 0.0f, // 2
	-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, // 3
	+0.5f, -0.5f, -0.5f,	1.0f, 1.0f, // 0

	// 4765
	+0.5f, +0.5f, -0.5f,	1.0f, 1.0f, // 4
	-0.5f, +0.5f, -0.5f,	0.0f, 1.0f, // 7
	-0.5f, +0.5f, +0.5f,	0.0f, 0.0f, // 6

	-0.5f, +0.5f, +0.5f,	0.0f, 0.0f, // 6
	+0.5f, +0.5f, +0.5f,	1.0f, 0.0f, // 5
	+0.5f, +0.5f, -0.5f,	1.0f, 1.0f, // 4

	// 0451
	+0.5f, -0.5f, -0.5f,	0.0f, 1.0f, // 0
	+0.5f, +0.5f, -0.5f,	1.0f, 1.0f, // 4
	+0.5f, +0.5f, +0.5f,	1.0f, 0.0f, // 5

	+0.5f, +0.5f, +0.5f,	1.0f, 0.0f, // 5
	+0.5f, -0.5f, +0.5f,	0.0f, 0.0f, // 1
	+0.5f, -0.5f, -0.5f,	0.0f, 1.0f, // 0

	// 1562
	+0.5f, -0.5f, +0.5f,	1.0f, 0.0f, // 1
	+0.5f, +0.5f, +0.5f,	1.0f, 1.0f, // 5
	-0.5f, +0.5f, +0.5f,	0.0f, 1.0f, // 6

	-0.5f, +0.5f, +0.5f,	0.0f, 1.0f, // 6
	-0.5f, -0.5f, +0.5f,	0.0f, 0.0f, // 2
	+0.5f, -0.5f, +0.5f,	1.0f, 0.0f, // 1

	// 2673
	-0.5f, -0.5f, +0.5f,	0.0f, 0.0f, // 2
	-0.5f, +0.5f, +0.5f,	1.0f, 0.0f, // 6
	-0.5f, +0.5f, -0.5f,	1.0f, 1.0f, // 7

	-0.5f, +0.5f, -0.5f,	1.0f, 1.0f, // 7
	-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, // 3
	-0.5f, -0.5f, +0.5f,	0.0f, 0.0f, // 2

	// 4037
	+0.5f, +0.5f, -0.5f,	1.0f, 1.0f, // 4
	+0.5f, -0.5f, -0.5f,	1.0f, 0.0f, // 0
	-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, // 3

	-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, // 3
	-0.5f, +0.5f, -0.5f,	0.0f, 1.0f, // 7
	+0.5f, +0.5f, -0.5f,	1.0f, 1.0f, // 4
*/

/*
	+0.5f, -0.5f, -0.5f,	1.0f, 1.0f, // 0
	+0.5f, -0.5f, +0.5f,	1.0f, 0.0f, // 1
	-0.5f, -0.5f, +0.5f,	0.0f, 0.0f, // 2
	-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, // 3
	+0.5f, +0.5f, -0.5f,	1.0f, 1.0f, // 4
	+0.5f, +0.5f, +0.5f,	1.0f, 0.0f, // 5
	-0.5f, +0.5f, +0.5f,	0.0f, 0.0f, // 6
	-0.5f, +0.5f, -0.5f,	0.0f, 1.0f  // 7
*/

void			vbo(GLuint *vbo, const float *vertices, size_t size)
{
	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW); // copy the vertex data
}
