#ifndef BMP_IMG_LOADER_H
# define BMP_IMG_LOADER_H

# include <stdio.h>

/*
** total        : 14 bytes
** type         : magic number ("BM")
** size         : total file size in bytes
** reserved1    : reserved value
** reserved2    : reserved value
** offset       : offset to data in bytes
*/

typedef struct  s_bmp_header {
   unsigned short int   type;
   unsigned int         size;
   unsigned short int   reserved1;
   unsigned short int   reserved2;
   unsigned int         offset;
}               t_bmp_header;

/*
** total            : 40 bytes
** size             : Header size in bytes
** width            : Width of image
** height           : Height of image
** planes           : Number of colour planes
** bits             : Bits per pixel (1, 4, 8, 24)
** compression      : Compression type
**  0 - no compression
**  1 - 8 bit run length encoding
**  2 - 4 bit run length encoding
**  3 - RGB bitmap with mask
** imagesize        : Image size in bytes
** xresolution      : Pixels per meter
** yresolution      : Pixels per meter
** nolours          : Number of colours
** importantcolours : Important colours
*/

typedef struct  s_bmp_info {
   unsigned int         size;
   int                  width;
   int                  height;
   unsigned short int   planes;
   unsigned short int   bits;
   unsigned int         compression;
   unsigned int         imagesize;
   int                  xresolution;
   int                  yresolution;
   unsigned int         ncolours;
   unsigned int         importantcolours;
}               t_bmp_info;

/*
** optional (mandatory for color depths ≤ 8 bits)
*/

/*
typedef struct  s_bmp_palette {
    ;
}
*/

/*
** 24-bit   : BGR
** indexed  : BGRA (A unused)
*/

unsigned char  *load_bmp_img(FILE *ptr, int *width, int *height);

#endif