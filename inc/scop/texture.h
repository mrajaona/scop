#ifndef TEXTURE_H
# define TEXTURE_H

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

# include "img_loader.h"

# define N_TEXTURES 2

void	bw_checkerboard(void);
void	texture_init(GLuint textures[N_TEXTURES], const GLuint shader);

#endif