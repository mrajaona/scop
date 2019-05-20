#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# define N_TEXTURES 2

/* GLFW */
# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# include <GLFW/glfw3.h>
/* GLFW */

# include "shader_struct.h"

# include "mat4.h"

typedef struct	s_arrays
{
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;
}				t_arrays;

typedef struct	s_data
{
	GLFWwindow	*window;
	t_shader	shader;
	GLuint		textures[N_TEXTURES];
	t_mat4		view;
	t_mat4		proj;
	t_mat4		model;
	t_arrays	arrays;
}				t_data;

#endif
