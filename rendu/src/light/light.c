#include "light.h"

static int		vao(GLuint *vao)
{
	glGenVertexArrays(1, vao); // generate
	glBindVertexArray(*vao); // make active
	return (1);
}

/*
** place all points in space
** pos
** x y z
*/

static int		vbo(GLuint *vbo)
{
	float			vertices[] = {
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f, 

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f, 

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f, 

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,  

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f, 

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f
	};

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy the vertex data

	return (1);
}

int				process_light(t_data *data)
{
	GLint pos_attrib;

	if (!vao(&(data->light.arrays.vao)))
		return (0);
	if (!vbo(&(data->light.arrays.vbo)))
		return (0);
	
	pos_attrib = glGetAttribLocation(data->light.shader.program, "position");
	glVertexAttribPointer(pos_attrib, 3, GL_FLOAT, GL_FALSE,
		3 * sizeof(float), 0);
	glEnableVertexAttribArray(pos_attrib);

	use_no_model();

	return (1);
}