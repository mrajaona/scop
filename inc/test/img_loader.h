#ifndef IMG_LOADER_H
# define IMG_LOADER_H

/* GLFW */
# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# include <GLFW/glfw3.h>
/* GLFW */

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "SOIL.h"

# define TEX_FORMAT GL_RGB

# define BMP_MAGIC "\x42\x4D"
# define PNG_MAGIC "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A"
# define JPG_MAGIC "\xFF\xD8\xFF"

int	load_img(const char *path);

#endif
