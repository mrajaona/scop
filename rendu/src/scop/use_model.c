#include "use_model.h"

void		use_no_model(void)
{
	glBindVertexArray(0);
	glUseProgram(0);	
}

void		use_model(const t_info *model)
{
	glBindVertexArray(model->arrays.vao);
	glUseProgram(model->shader.program);
}
