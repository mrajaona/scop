#include "floor.h"

/*
** link points in order
*/

static void	ebo(GLuint *ebo)
{
	const GLuint	elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	glGenBuffers(1, ebo); // generate
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo); // make active
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}

static void	vao(GLuint *vao)
{
	glGenVertexArrays(1, vao); // generate
	glBindVertexArray(*vao); // make active
}

/*
** place all points in space
** pos		color	tex
** x y z	r g b	u v
*/
static void	vbo(GLuint *vbo)
{
	const float	vertices[] = {
		-1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		+1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		+1.0f, +1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		+1.0f, +1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-1.0f, +1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
	};

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy the vertex data
}

static void	stencil(const t_data *data, const t_mat4 model)
{
	GLint uniModel = glGetUniformLocation(data->shader.program, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);

	glEnable(GL_STENCIL_TEST);

	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glStencilMask(0xFF);
	glDepthMask(GL_FALSE);
	glClear(GL_STENCIL_BUFFER_BIT);
	
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisable(GL_STENCIL_TEST);
}

void	set_floor(t_model *model)
{
	identity(model->mat);
	vbo(&(model->vbo));
	vao(&(model->vao));
	ebo(&(model->ebo));
}

void	draw_floor(const t_data *data, const t_mat4 edit)
{
	t_mat4	model;

	mat4_mult(data->floor.mat, edit, model);
	model_select(data->shader.program, &(data->floor));
	stencil(data, model);
}