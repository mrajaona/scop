#ifndef IMG_LOADER_H
# define IMG_LOADER_H

# include <errno.h>
# include <stdio.h>
# include <string.h>

# include "common.h"

# include "SOIL.h" // tmp

# include "bmp_img_loader.h"
# include "error.h"

int	load_img(const char *path);

# define BMP_MAGIC "\x42\x4D"
# define PNG_MAGIC "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A"
# define JPG_MAGIC "\xFF\xD8\xFF"

#endif