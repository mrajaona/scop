#include "depth.h"

static int	depth_fbo(t_data *data)
{
	// The framebuffer, which regroups 0, 1, or more textures, and 0 or 1 depth buffer.
	glGenFramebuffers(1, &(data->depth.fbo));
	glBindFramebuffer(GL_FRAMEBUFFER, data->depth.fbo);

	// Depth texture. Slower than a depth buffer, but you can sample it later in your shader
	glGenTextures(1, &(data->depth.map));
	glBindTexture(GL_TEXTURE_2D, data->depth.map);
	glTexImage2D(GL_TEXTURE_2D, 0,GL_DEPTH_COMPONENT16, DEPTH_WIDTH, DEPTH_HEIGHT, 0,GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, data->depth.map, 0);

	glDrawBuffer(GL_NONE); // No color buffer is drawn to.

	// Always check that our framebuffer is ok
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return (0);

	return (1);
}

static void	depth_model(t_depth *depth)
{
	GLint	uni_model;

	identity(depth->mat_model);

	uni_model = glGetUniformLocation(depth->shader.program, "model");
	glUniformMatrix4fv(uni_model, 1, GL_FALSE, depth->mat_model);
}

static void	depth_view(t_depth *depth)
{
	GLint		uni_view;

	t_vector	lightPos;
	t_vector	target;
	t_vector 	up;

	coord_to_vec(5.0f, 5.0f, 0.0f, lightPos);
	coord_to_vec(0, 0, 0, target);
	coord_to_vec(0, 1, 0, up);

	lookat(depth->mat_view, lightPos, target, up);

	uni_view = glGetUniformLocation(depth->shader.program, "view");
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, depth->mat_view);
}

static void	depth_proj(t_depth *depth)
{
	GLint	uni_proj;
	t_ortho	params;

	params.left = -10;
	params.right = 10;
	params.bottom = -10;
	params.top = 10;
	params.near = -10;
	params.far = 20;

	orthographic(depth->mat_proj, params);

	uni_proj = glGetUniformLocation(depth->shader.program, "proj");
	glUniformMatrix4fv(uni_proj, 1, GL_FALSE, depth->mat_proj);
}

void	depth(t_data *data)
{
	t_matrices	matrices;
	t_mat4		depth_mvp;

	if (!depth_fbo(data))
	{
		fprintf(stderr, "fbo failed\n");
		fflush(stderr);			
		return ;
	}

	// Compute the MVP matrix from the light's point of view
	depth_model(&(data->depth));
	depth_view(&(data->depth));
	depth_proj(&(data->depth));

	mat4_mult(matrices.model, matrices.view, depth_mvp);
	mat4_mult(depth_mvp, matrices.proj, depth_mvp);

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	GLint		uni_depth;
	uni_depth = glGetUniformLocation(data->model.shader.program, "depthMatrix");
	glUniformMatrix4fv(uni_depth, 1, GL_FALSE, depth_mvp);
}
