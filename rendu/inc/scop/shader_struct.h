#ifndef SHADER_STRUCT_H
# define SHADER_STRUCT_H

# include "glfw_inc.h"

typedef struct	s_shader
{
	GLuint	program;
	GLuint	vertex;
	GLuint	fragment;
}				t_shader;

#endif
