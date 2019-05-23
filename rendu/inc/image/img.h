#ifndef IMG_H
# define IMG_H

/* GLFW */
# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# include <GLFW/glfw3.h>
/* GLFW */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# include "SOIL.h"

# include "img_bmp.h"

# define TEX_FORMAT GL_RGB

# define PNG_MAGIC "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A"
# define JPG_MAGIC "\xFF\xD8\xFF"

int				load_img(const char *path);

#endif