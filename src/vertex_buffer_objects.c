#include "tuto.h"

void vbo(GLuint *vbo)
{
	float vertices[] = {
		0.0f, 0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1: Red
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // Vertex 2: Green
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f // Vertex 3: Blue
	};

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy the vertex data
	/*
	** • GL_STATIC_DRAW		: The vertex data will be uploaded once and drawn many times (e.g. the world).
	** • GL_DYNAMIC_DRAW	: The vertex data will be created once, changed from time to time, but drawn many times more than that.
	** • GL_STREAM_DRAW		: The vertex data will be uploaded once and drawn once.
	*/
}
