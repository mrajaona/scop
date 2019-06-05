#include "depth.h"

int framebuffer(t_data *data)
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

static void	depth_model(t_mat4 model)
{
	identity(model);
}

static void	depth_view(t_mat4 view)
{

	t_vector	lightPos;
	t_vector	target;
	t_vector 	up;

	coord_to_vec(5.0f, 5.0f, 0.0f, lightPos);
	coord_to_vec(0, 0, 0, target);
	coord_to_vec(0, 1, 0, up);

	lookat(view, lightPos, target, up);
}

static void	depth_proj(t_mat4 proj)
{
	t_ortho	params;

	params.left = -10;
	params.right = 10;
	params.bottom = -10;
	params.top = 10;
	params.near = -10;
	params.far = 20;

	orthographic(proj, params);
}

void	testing(t_data *data)
{
	t_matrices	matrices;
	t_mat4		depth_mvp;

	// Compute the MVP matrix from the light's point of view
	depth_model(matrices.model);
	depth_view(matrices.view);
	depth_proj(matrices.proj);

	mat4_mult(matrices.model, matrices.view, depth_mvp);
	mat4_mult(depth_mvp, matrices.proj, depth_mvp);

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	GLint		uni_depth;
	uni_depth = glGetUniformLocation(data->model.shader.program, "depthMatrix");
	glUniformMatrix4fv(uni_depth, 1, GL_FALSE, depth_mvp);
}
