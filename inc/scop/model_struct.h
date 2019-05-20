#ifndef MODEL_STRUCT_H
# define MODEL_STRUCT_H

/* GLFW */
# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# include <GLFW/glfw3.h>
/* GLFW */

# include "mat4.h"

typedef struct	s_model
{
	t_mat4		mat;
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;	
}				t_model;

#endif
