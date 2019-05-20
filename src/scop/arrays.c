#include "arrays.h"

/*
** link points in order
*/

void			ebo(GLuint *ebo)
{
	const GLuint	elements[] = {
		0, 1, 2,
		2, 3, 0
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
** pos		color	tex
** x y z	r g b	u v
*/
void			vbo(GLuint *vbo)
{
	const float	vertices[] = {

		// cube

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		+0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		+0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		+0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

		-0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		+0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	};

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy the vertex data
}
