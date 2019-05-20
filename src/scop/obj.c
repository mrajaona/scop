#include "obj.h"

static void	stencil_cube()
{
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

static void	stencil_floor(const t_data *data, const t_mat4 model)
{
	GLint uniModel = glGetUniformLocation(data->shader.program, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);

	glEnable(GL_STENCIL_TEST);

	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glStencilMask(0xFF);
	glDepthMask(GL_FALSE);
	glClear(GL_STENCIL_BUFFER_BIT);
	
	glDrawArrays(GL_TRIANGLES, 36, 6);

	glDisable(GL_STENCIL_TEST);
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
	stencil_cube(data, model);
}

void		draw_floor(const t_data *data, const t_mat4 edit)
{
	t_mat4	model;

	mat4_mult(data->floor.mat, edit, model);
	stencil_floor(data, model);
}

void		draw_cube_reflection(const t_data *data, const t_mat4 edit)
{
	t_mat4	model;

	mat4_mult(data->model.mat, edit, model);
	stencil_reflection(data, model);
}
