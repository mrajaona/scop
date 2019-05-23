#ifndef ARRAYS_H
# define ARRAYS_H

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

void			ebo(GLuint *ebo);
void			vao(GLuint *vao);
void			vbo(GLuint *vbo);

#endif
