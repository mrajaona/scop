#ifndef SHADOW_H
# define SHADOW_H

// # include "glfw_inc.h"
# include "glew_inc.h"

# include "data_struct.h"

# include "mat4.h"
# include "mat4_op.h"
# include "vector.h"
# include "coord.h"

# include "lookat.h"
# include "orthographic.h"

# include "perspective.h"

void	bind_fbo_w(GLuint fbo);
void	bind_fbo_r(GLuint fbo, GLenum TextureUnit);
void	shadow(t_data *data);

#endif