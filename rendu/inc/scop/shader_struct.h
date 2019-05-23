#ifndef SHADER_STRUCT_H
# define SHADER_STRUCT_H

/* GLFW */
# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# include <GLFW/glfw3.h>
/* GLFW */

typedef struct	s_shader
{
	GLuint	program;
	GLuint	vertex;
	GLuint	fragment;
}				t_shader;

#endif
