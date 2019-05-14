#ifndef MODEL_H
# define MODEL_H

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

# include "mat4.h"

typedef struct	s_model
{
	t_mat4		mat;
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;	
}				t_model;

void	model_del(t_model *model);
void	model_clr(t_model *model);
void	model_select(t_model *model);
void	set_model(t_data *data, t_model *model);

#endif