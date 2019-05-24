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

void			ebo(GLuint *ebo)
{
	/*
		f 1 2 3 4
		f 5 8 7 6
		f 1 5 6 2
		f 2 6 7 3
		f 3 7 8 4
		f 5 1 4 8
	*/
	const GLuint	elements[] = {
		0, 1, 2,
		3, 4, 5,
		6, 7, 8,
		9, 10, 11,
		12, 13, 14,
		15, 16, 17,
		18, 19, 20,
		21, 22, 23,
		24, 25, 26,
		27, 28, 29,
		30, 31, 32,
		33, 34, 35
	};

	glGenBuffers(1, ebo); // generate
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo); // make active
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
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
void			vbo(GLuint *vbo)
{
	/*
		v0  0.250000 -0.250000 -0.250000
		v1  0.250000 -0.250000  0.250000
		v2 -0.250000 -0.250000  0.250000
		v3 -0.250000 -0.250000 -0.250000
		v4  0.250000  0.250000 -0.250000
		v5  0.250000  0.250000  0.250000
		v6 -0.250000  0.250000  0.250000
		v7 -0.250000  0.250000 -0.250000
	*/

	const float	vertices[] = {

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

	};

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy the vertex data
}
