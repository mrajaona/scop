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

# define SHADOW_WIDTH 1024
# define SHADOW_HEIGHT 1024

typedef struct	s_matrices
{
	t_mat4 model;
	t_mat4 view;
	t_mat4 proj;
}				t_matrices;

#endif