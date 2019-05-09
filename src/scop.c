#include "scop.h"

// GLEW

static void	glew_init(GLuint *vertexBuffer)
{
	glewExperimental = GL_TRUE;
	int err;
	if ((err = glewInit()) != GLEW_OK)
	{
		fprintf(stderr, "glew init error\n%s\n", glewGetErrorString(err));
		fflush(stderr);
		exit(1);
	}
	glGenBuffers(1, vertexBuffer);
}

static void	init(t_data *scop)
{
	glfw_init(&(scop->window));
	glew_init(&(scop->vertexBuffer));
	vbo(&(scop->vbo));
	vao(&(scop->vao));
	ebo(&(scop->ebo));
	shader_program(&(scop->shaderProgram), scop);
	tex(scop->textures, scop);
}

static void	clr_scop(t_data *scop)
{
	unsigned int i;

	scop->window = NULL;
	scop->vertexBuffer = 0;
	scop->vbo = 0;
	scop->vao = 0;
	scop->ebo = 0;	
	scop->vertexShader = 0;
	scop->fragmentShader = 0;
	scop->shaderProgram = 0;
	i = 0;
	while (i < N_TEXTURES)
	{
		scop->textures[i] = 0;
		i++;
	}
}

#include "vector.h"
#include "matrix.h"
#include "matrix_op.h"
#include "matrix_lookat.h"
#include "matrix_perspective.h"
#include "matrix_rotations.h"
#include "angle.h"
#include "error.h"

int			main(void)
{
	t_data	scop;
	clr_scop(&scop);
	init(&scop);

	// debug

	t_mat4		model;
	
	identity(model);

	// t_vector	edit;
	// coord_to_vec(0.5f, 1.0f, 1.0f, edit);	
	// scaling(edit, model);
	// rotatez(deg_to_rad(180.0f), model);

	GLint uniTrans = glGetUniformLocation(scop.shaderProgram, "model");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, model);

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

	coord_to_vec(0, 0, 0, eye);
	coord_to_vec(0, 0, 1, target);
	coord_to_vec(0, 1, 0, up);

	lookat(eye, target, up, view);

	GLint uniView = glGetUniformLocation(scop.shaderProgram, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, view);

	// fov
	t_mat4		proj;

	identity(proj);

	// float		planes[2];
	// float		vfov;
	// float		ratio;

	// // example
	// // vfov = deg_to_rad(45.0f);
	// // ratio = 800.0f / 600.0f;
	// // planes[NEAR_PLANE] = 1.0f;
	// // planes[FAR_PLANE] = 10.0f;

	// vfov = deg_to_rad(45.0f);
	// ratio = 800.0f / 600.0f;
	// planes[NEAR_PLANE] = 1.0f;
	// planes[FAR_PLANE] = 10.0f;

	// perspective(vfov, ratio, planes, proj);

	GLint uniProj = glGetUniformLocation(scop.shaderProgram, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, proj);

	// end

	show(&scop);
	ft_exit(&scop, 0);
	// return (0);
}
