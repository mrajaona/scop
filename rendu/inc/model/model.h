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

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "data_struct.h"

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_model
{
	t_list		*vertices;		// float tmp_vertices[3];
	size_t		nvertices;
	t_list		*faces; 		// GLuint	faces[3];
	size_t		nfaces;
}				t_model;

int				load_model(const char *path, t_data *data);

#endif
