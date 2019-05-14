#include "model.h"

void	model_del(t_model *model)
{
	glDeleteBuffers(1, &(model->ebo));
	glDeleteBuffers(1, &(model->vbo));
	glDeleteVertexArrays(1, &(model->vao));	
}

void	model_clr(t_model *model)
{
	mat4_clr(model->mat);
	model->ebo = 0;
	model->vbo = 0;
	model->vao = 0;
}

void	model_select(t_model *model)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->ebo); // make active
	glBindVertexArray(model->vao); // make active
	glBindBuffer(GL_ARRAY_BUFFER, model->vbo); // make active array buffer
}