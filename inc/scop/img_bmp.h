#ifndef IMG_BMP_H
# define IMG_BMP_H

# define BMP_MAGIC "\x42\x4D"

unsigned char	*load_bmp(FILE *ptr, int *width, int *height);

#endif
