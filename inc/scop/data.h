#ifndef DATA_H
# define DATA_H

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

# include <stdlib.h>

# include "data_struct.h"

void			data_clr(t_data *data);
void			data_exit(t_data *data, const int status);

#endif
