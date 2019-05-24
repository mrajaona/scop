#ifndef GLEW_INC_H
# define GLEW_INC_H

/* GLEW */
# ifdef __APPLE__
/*
#  define GLEW_STATIC
#  define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#  define GLFW_INCLUDE_GLCOREARB
#  include "glew.h"
*/
# else
#  define GLEW_STATIC
#  include <GL/glew.h>
# endif
/* GLEW */

#endif
