#include "tuto.h"

void	vao(GLuint *vao)
{
	glGenVertexArrays(1, vao); // generate
	glBindVertexArray(*vao); // make active
}