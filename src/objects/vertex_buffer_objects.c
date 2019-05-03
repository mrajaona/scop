#include "object.h"

void	vbo(GLuint *vbo)
{
	const float	vertices[] = {
		-0.5f, +0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
		+0.5f, +0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
		+0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
		-0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
	};

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy the vertex data
}
