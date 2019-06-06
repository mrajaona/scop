#include "shadow.h"

static int	shadow_fbo(t_data *data)
{
	// The framebuffer, which regroups 0, 1, or more textures, and 0 or 1 shadow buffer.
	glGenFramebuffers(1, &(data->shadow.fbo));
	glBindFramebuffer(GL_FRAMEBUFFER, data->shadow.fbo);

	// Depth texture. Slower than a shadow buffer, but you can sample it later in your shader
	glGenTextures(1, &(data->shadow.map));
	glBindTexture(GL_TEXTURE_2D, data->shadow.map);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, data->shadow.map, 0);

	glDrawBuffer(GL_NONE); // No color buffer is drawn to.

	// Always check that our framebuffer is ok
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return (0);

	return (1);
}

static void	shadow_model(t_shadow *shadow)
{
	GLint	uni_model;

	identity(shadow->mat_model);

	uni_model = glGetUniformLocation(shadow->shader.program, "model");
	glUniformMatrix4fv(uni_model, 1, GL_FALSE, shadow->mat_model);
}

static void	shadow_view(t_shadow *shadow)
{
	GLint		uni_view;

	t_vector	lightPos;
	t_vector	target;
	t_vector 	up;

	coord_to_vec(5.0f, 5.0f, 0.0f, lightPos);
	coord_to_vec(0, 0, 0, target);
	coord_to_vec(0, 1, 0, up);

	lookat(shadow->mat_view, lightPos, target, up);

	uni_view = glGetUniformLocation(shadow->shader.program, "view");
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, shadow->mat_view);
}

static void	shadow_proj(t_shadow *shadow)
{
	GLint	uni_proj;
	t_ortho	params;

	params.left = -10;
	params.right = 10;
	params.bottom = -10;
	params.top = 10;
	params.near = -10;
	params.far = 20;

	orthographic(shadow->mat_proj, params);

	uni_proj = glGetUniformLocation(shadow->shader.program, "proj");
	glUniformMatrix4fv(uni_proj, 1, GL_FALSE, shadow->mat_proj);
}

void	shadow(t_data *data)
{
	t_matrices	matrices;
	t_mat4		shadow_mvp;

	if (!shadow_fbo(data))
	{
		fprintf(stderr, "fbo failed\n");
		fflush(stderr);			
		return ;
	}

	// Compute the MVP matrix from the light's point of view
	shadow_model(&(data->shadow));
	shadow_view(&(data->shadow));
	shadow_proj(&(data->shadow));

	mat4_mult(matrices.model, matrices.view, shadow_mvp);
	mat4_mult(shadow_mvp, matrices.proj, shadow_mvp);

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	GLint		uni_shadow;
	uni_shadow = glGetUniformLocation(data->model.shader.program, "shadowMatrix");
	glUniformMatrix4fv(uni_shadow, 1, GL_FALSE, shadow_mvp);
}
