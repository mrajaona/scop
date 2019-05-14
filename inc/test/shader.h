#ifndef SHADER_H
# define SHADER_H

/* GLEW */
# define GLEW_STATIC

# ifdef __APPLE__
#  define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#  define GLFW_INCLUDE_GLCOREARB
#  include "glew.h"
# else
#  include <GL/glew.h>
# endif
/* GLEW */

# include "stdio.h"

typedef struct	s_shader
{
	GLuint	program;
	GLuint	vertex;
	GLuint	fragment;
}				t_shader;

void	shader_del(t_shader *shader);
int		shader_init(t_shader *shader);

#endif