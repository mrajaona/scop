#include "set_data.h"

void 			set_model(t_data *data)
{
	identity(data->model);

	// fprintf(stdout, "\nmodel");
	// mat4_print(data->model);

	GLint uniModel = glGetUniformLocation(data->shader.program, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, data->model);
}

// The camera in OpenGL cannot move and is defined
// to be located at (0,0,0) facing the negative Z direction
void			set_view(t_data *data)
	{
	identity(data->view);

	t_vector	eye;
	t_vector	target;
	t_vector 	up;

	// example
	coord_to_vec(1.2f, 1.2f, 1.2f, eye);
	coord_to_vec(0, 0, 0, target);
	coord_to_vec(0, 0, 1, up);

	lookat(eye, target, up, data->view);
	
	// fprintf(stdout, "\nview");
	// mat4_print(data->view);

	GLint uniView = glGetUniformLocation(data->shader.program, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, data->view);
}

void			set_proj(t_data *data)
{
	identity(data->proj);

	float		planes[2];
	float		vfov;
	float		ratio;

	// example
	// vfov = deg_to_rad(45.0f);
	vfov = deg_to_rad(80.0f);
	ratio = 800.0f / 600.0f;
	planes[NEAR_PLANE] = 1.0f;
	planes[FAR_PLANE] = 10.0f;

	perspective(vfov, ratio, planes, data->proj);

	// fprintf(stdout, "\nproj");
	// mat4_print(data->proj);

	GLint uniProj = glGetUniformLocation(data->shader.program, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, data->proj);
}
