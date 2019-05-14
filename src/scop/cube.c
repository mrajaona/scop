#include "cube.h"

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
		-0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
	};

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy the vertex data
}

void	set_cube(t_model *model)
{
	identity(model->mat);
	vbo(&(model->vbo));
	vao(&(model->vao));
	ebo(&(model->ebo));
}

static void	stencil_cube()
{
	glDrawArrays(GL_TRIANGLES, 0, 36);
}


static void stencil_reflection(const t_data *data, t_mat4 model)
{
	GLint uniColor;

	uniColor = glGetUniformLocation(data->shader.program, "overrideColor");

	glEnable(GL_STENCIL_TEST);

	glStencilFunc(GL_EQUAL, 1, 0xFF);
	glStencilMask(0x00);
	glDepthMask(GL_TRUE);

	t_vector	edit;

	coord_to_vec(1.0f, 1.0f, -1.0f, edit);
	scaling(edit, model);

	coord_to_vec(0.0f, 0.0f, -1.0f, edit);
	translation(edit, model);

	GLint uniModel = glGetUniformLocation(data->shader.program, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);

	glUniform3f(uniColor, 0.3f, 0.3f, 0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);

	glDisable(GL_STENCIL_TEST);
}

void		draw_cube(const t_data *data, const t_mat4 edit)
{
	t_mat4	model;

	mat4_mult(data->model.mat, edit, model);
	model_select(data->shader.program, &(data->model));
	stencil_cube(data, model);
}

void		draw_cube_reflection(const t_data *data, const t_mat4 edit)
{
	t_mat4	model;

	mat4_mult(data->model.mat, edit, model);
	model_select(data->shader.program, &(data->model));
	stencil_reflection(data, model);
}
