#include "scene.h"

static void	set_view(t_data *data)
	{
	identity(data->view);

	t_vector	eye;
	t_vector	target;
	t_vector 	up;

	coord_to_vec(1.2f, 1.2f, 1.2f, eye);
	coord_to_vec(0, 0, 0, target);
	coord_to_vec(0, 0, 1, up);

	lookat(eye, target, up, data->view);
	
	fprintf(stdout, "\nview");
	mat4_print(data->view);

	GLint uniView = glGetUniformLocation(data->shader.program, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, data->view);
}

static void	set_proj(t_data *data)
{
	identity(data->proj);

	float		planes[2];
	float		vfov;
	float		ratio;

	// vfov = deg_to_rad(45.0f);
	vfov = deg_to_rad(80.0f);
	ratio = 800.0f / 600.0f;
	planes[NEAR_PLANE] = 1.0f;
	planes[FAR_PLANE] = 10.0f;
	
	perspective(vfov, ratio, planes, data->proj);

	fprintf(stdout, "\nproj");
	mat4_print(data->proj);

	GLint uniProj = glGetUniformLocation(data->shader.program, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, data->proj);
}

void		set_scene(t_data *data)
{
	set_view(data);
	set_proj(data);
}
