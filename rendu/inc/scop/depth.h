#ifndef DEPTH_H
# define DEPTH_H

// # include "glfw_inc.h"
# include "glew_inc.h"

# include "data_struct.h"

# include "mat4.h"
# include "mat4_op.h"
# include "vector.h"
# include "coord.h"

# include "lookat.h"
# include "orthographic.h"

# define DEPTH_WIDTH 1024
# define DEPTH_HEIGHT 1024

typedef struct	s_matrices
{
	t_mat4 model;
	t_mat4 view;
	t_mat4 proj;
}				t_matrices;

void	depth(t_data *data);


#endif