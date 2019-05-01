#include "tuto.h"

void vbo(GLuint *vbo)
{
	const float	vertices[] = {
		-0.5f, 0.5f, 1.0f, 0.0f, 0.0f,	// TL
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f,	// TR
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f,	// BL
		-0.5f, -0.5f, 1.0f, 1.0f, 1.0f	// BR
	};

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy the vertex data
}
