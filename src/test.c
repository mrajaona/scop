#include "gl_loader.h"
#include "common.h"
#include "vector.h"
#include "matrix.h"
#include "matrix_op.h"
#include "matrix_lookat.h"
#include "matrix_perspective.h"
#include "matrix_rotations.h"
#include "angle.h"
#include "error.h"

static void	mat4_print(t_mat4 mat)
{
	fprintf(stdout, "\n");
	fprintf(stdout, "% .2f % .2f % .2f % .2f\n",
		mat4_get(mat, 0, 0),
		mat4_get(mat, 1, 0),
		mat4_get(mat, 2, 0),
		mat4_get(mat, 3, 0)
		);
	fprintf(stdout, "% .2f % .2f % .2f % .2f\n",
		mat4_get(mat, 0, 1),
		mat4_get(mat, 1, 1),
		mat4_get(mat, 2, 1),
		mat4_get(mat, 3, 1)
		);
	fprintf(stdout, "% .2f % .2f % .2f % .2f\n",
		mat4_get(mat, 0, 2),
		mat4_get(mat, 1, 2),
		mat4_get(mat, 2, 2),
		mat4_get(mat, 3, 2)
		);
	fprintf(stdout, "% .2f % .2f % .2f % .2f\n",
		mat4_get(mat, 0, 3),
		mat4_get(mat, 1, 3),
		mat4_get(mat, 2, 3),
		mat4_get(mat, 3, 3)
		);
	fprintf(stdout, "\n");

	fflush(stdout);	
}

static void set_model(t_data *scop)
{
	t_mat4		model;
	
	identity(model);

	// t_vector	edit;
	// coord_to_vec(.0f, 1.0f, 0.0f, edit);	
	// // scaling(edit, model);

	// translation(edit, model);

	// rotatez(deg_to_rad(180.0f), model);

	mat4_print(model);

	GLint uniTrans = glGetUniformLocation(scop->shaderProgram, "model");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, model);
}

static void	set_view(t_data *scop)
	{
	// camera

	t_mat4		view;

	identity(view);

	t_vector	eye;
	t_vector	target;
	t_vector 	up;

	// example
	// coord_to_vec(1.2f, 1.2f, 1.2f, eye);
	// coord_to_vec(0, 0, 0, target);
	// coord_to_vec(0, 0, 1, up);

	// identity
	// coord_to_vec(0, 0, 0, eye);
	// coord_to_vec(0, 0, -1, target);
	// coord_to_vec(0, 1, 0, up);

	coord_to_vec(0, 0, 0, eye);
	coord_to_vec(0, 0, -1, target);
	coord_to_vec(0, 1, 0, up);

	mat4_print(view);
	// lookat(eye, target, up, view);

	GLint uniView = glGetUniformLocation(scop->shaderProgram, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, view);
}

static void	set_proj(t_data *scop)
{
	// fov
	t_mat4		proj;

	identity(proj);

	// float		planes[2];
	// float		vfov;
	// float		ratio;

	// // example
	// vfov = deg_to_rad(45.0f);
	// ratio = 800.0f / 600.0f;
	// planes[NEAR_PLANE] = 1.0f;
	// planes[FAR_PLANE] = 10.0f;

	// // vfov = deg_to_rad(45.0f);
	// // ratio = 800.0f / 600.0f;
	// // planes[NEAR_PLANE] = 1.0f;
	// // planes[FAR_PLANE] = 10.0f;

	mat4_print(proj);
	// perspective(vfov, ratio, planes, proj);

	GLint uniProj = glGetUniformLocation(scop->shaderProgram, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, proj);
}


void	do_matrix_stuff(t_data *scop)
{
	set_model(scop);
	set_view(scop);
	set_proj(scop);
}
