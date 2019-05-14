void	set_model(t_data *data)
{
	identity(data->model);

	GLint uniModel = glGetUniformLocation(data->shaderProgram, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, data->model);
}