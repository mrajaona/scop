#ifndef SCOP_H
# define SCOP_H

/* GLEW */ // prevent conflict
# define GLEW_STATIC

# ifdef __APPLE__
#  define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#  define GLFW_INCLUDE_GLCOREARB
#  include "glew.h"
# else
#  include <GL/glew.h>
# endif
/* GLEW */

# include "data_struct.h"

# include "data.h"
# include "init_ext.h"
# include "arrays.h"
# include "shader.h"
# include "texture.h"
# include "set_data.h"
# include "show.h"

#endif
