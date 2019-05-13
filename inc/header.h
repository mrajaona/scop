
#ifndef ANGLE_H
# define ANGLE_H

# include <math.h>

float	deg_to_rad(const float angle);
float	rad_to_deg(const float angle);

#endif

// ------------------------------------------------------------

#ifndef BMP_IMG_LOADER_H
# define BMP_IMG_LOADER_H

# include <stdlib.h>
# include <stdio.h>
# include "img_format.h"

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

// ------------------------------------------------------------

#ifndef COMMON_H
# define COMMON_H

# include "glfw.h"
# include "matrix.h"

/*
** libc -lc
** <assert.h>
** <complex.h>
** <ctype.h>
** <errno.h>
** <fenv.h>
** <float.h>
** <inttypes.h>
** <iso646.h>
** <limits.h>
** <locale.h>
** <math.h>
** <setjmp.h>
** <signal.h>
** <stdalign.h>
** <stdarg.h>
** <stdatomic.h>
** <stdbool.h>
** <stddef.h>
** <stdint.h>
** <stdio.h>
** <stdlib.h>
** <stdnoreturn.h>
** <string.h>
** <tgmath.h>
** <threads.h>
** <time.h>
** <uchar.h>
** <wchar.h>
** <wctype.h>
*/

/*
** libm -libm
** <math.h>
** <stdlib.h>
*/

# define N_TEXTURES 2

typedef struct  s_data
{
	GLFWwindow	*window;
	GLuint		vertexBuffer;
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;	
	GLuint		vertexShader;
	GLuint		fragmentShader;
	GLuint		shaderProgram;
	GLuint		textures[N_TEXTURES];
	t_mat4		model;
	t_mat4		view;
	t_mat4		proj;
}			   t_data;

#endif

// ------------------------------------------------------------

#ifndef ERROR_H
# define ERROR_H

# include <stdlib.h>
# include <stdio.h>

#endif

// ------------------------------------------------------------

#ifndef EXIT_H
# define EXIT_H

# include <stdlib.h>
# include "gl_loader.h"
# include "common.h"

void	ft_exit(t_data *scop, const int status);

#endif

// ------------------------------------------------------------

#ifndef GLFW_H
# define GLFW_H

# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# include <GLFW/glfw3.h>
# include <stdio.h>

# include "common.h"
# include "error.h"

void	glfw_init(GLFWwindow **window);

#endif

// ------------------------------------------------------------

#ifndef GL_LOADER_H
# define GL_LOADER_H

# define GLEW_STATIC

# ifdef __APPLE__
#  define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#  define GLFW_INCLUDE_GLCOREARB
#  include "glew.h"
# else
#  include <GL/glew.h>
# endif

#endif

// ------------------------------------------------------------

#ifndef IMG_FORMAT_H
# define IMG_FORMAT_H

# define BYTES_PER_PIXEL 3
# define TEX_FORMAT GL_RGB

#endif

// ------------------------------------------------------------

#ifndef IMG_LOADER_H
# define IMG_LOADER_H

# include <errno.h>
# include <stdio.h>
# include <string.h>

# include "common.h"

# include "SOIL.h" // tmp

# include "img_format.h"
# include "bmp_img_loader.h"
# include "error.h"

int	load_img(const char *path);

# define BMP_MAGIC "\x42\x4D"
# define PNG_MAGIC "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A"
# define JPG_MAGIC "\xFF\xD8\xFF"

#endif

// ------------------------------------------------------------

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include <stdio.h>

/*
** reading matrices :
** x goes right
** y goes down
*/

typedef float	t_mat4[16];
typedef float	*t_mat4_ptr;

void			mat4_print(const t_mat4 mat);

void			mat4_set(t_mat4 mat,
	const unsigned char x, const unsigned char y,
	const float value);
float			mat4_get(const t_mat4 mat,
	const unsigned char x, const unsigned char y);

void			clear_matrix(t_mat4 mat);
void			identity(t_mat4 mat);

void			mat4_eq(t_mat4 dst, const t_mat4 src);
t_mat4_ptr		mat4_add(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_sub(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_scalar(const t_mat4 mat, const int scalar, t_mat4 res);
t_mat4_ptr		mat4_mult(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);

#endif

// ------------------------------------------------------------

#ifndef MATRIX_LOOKAT_H
# define MATRIX_LOOKAT_H

# include <math.h>
# include "matrix.h"
# include "vector.h"

void	lookat(const t_vector eye, const t_vector target, const t_vector up,
	t_mat4 dest);

#endif

// ------------------------------------------------------------

#ifndef MATRIX_OP_H
# define MATRIX_OP_H

# include <math.h>
# include "matrix.h"
# include "vector.h"

void			coord_to_vec(const float x, const float y, const float z,
	t_vector dest);
void			mat4_vector_prod(const t_mat4 lhs, const t_vector rhs,
	t_vector res);
void			transform(const t_mat4 trans, t_mat4 dest);
void			translation(const t_vector mov, t_mat4 dest);
void			scaling(const t_vector scale, t_mat4 dest);

#endif

// ------------------------------------------------------------

#ifndef MATRIX_PERSPECTIVE_H
# define MATRIX_PERSPECTIVE_H

# include <math.h>
# include "matrix.h"

/*
** plane[0] = near plane
** plane[1] = far plane
*/

# define NEAR_PLANE 0
# define FAR_PLANE 1

void	perspective(const float vfov, const float ratio, const float planes[2],
	t_mat4 dest);

#endif

// ------------------------------------------------------------

#ifndef MATRIX_ROTATIONS_H
# define MATRIX_ROTATIONS_H

# include <math.h>
# include "matrix.h"
# include "vector.h"
# include "matrix_op.h"
# include "angle.h"

void	rotatex(const float angle, t_mat4 dest);
void	rotatey(const float angle, t_mat4 dest);
void	rotatez(const float angle, t_mat4 dest);

#endif

// ------------------------------------------------------------

#ifndef OBJECT_H
# define OBJECT_H

# include "gl_loader.h"
# include "common.h"

void	vbo(GLuint *vbo);
void	vao(GLuint *vao);
void	ebo(GLuint *ebo);

#endif

// ------------------------------------------------------------

#ifndef SCOP_H
# define SCOP_H

# include "gl_loader.h"
# include "common.h"
# include "object.h"
# include "texture.h"
# include "shader.h"
# include "show.h"
# include "exit.h"

#endif

// ------------------------------------------------------------

#ifndef SHADER_H
# define SHADER_H

# include "gl_loader.h"
# include "common.h"
# include "error.h"
# include "exit.h"

void	shader_program(GLuint *shaderProgram, t_data *scop);

#endif

// ------------------------------------------------------------

#ifndef SHOW_H
# define SHOW_H

# include "gl_loader.h"
# include "common.h"
# include "matrix_rotations.h"

void	show(const t_data *scop);

#endif

// ------------------------------------------------------------

#ifndef TEXTURE_H
# define TEXTURE_H

# include "gl_loader.h"
# include "common.h"
# include "img_loader.h"
# include "error.h"

/*
** N_TEXTURES is defined in common.h
*/

void	tex(GLuint *tex, const t_data *scop);

#endif

// ------------------------------------------------------------

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef float	t_vector[4];
typedef float	*t_vector_ptr;

void			vector_print(const t_vector src);

void			clear_vector(t_vector vec);
void			vector_eq(t_vector dst, const t_vector src);
t_vector_ptr	vector_add(const t_vector lhs, const t_vector rhs,
	t_vector res);
t_vector_ptr	vector_sub(const t_vector lhs, const t_vector rhs,
	t_vector res);
t_vector_ptr	vector_scalar(const t_vector vec, const int scalar,
	t_vector res);

t_vector_ptr	coord_cross_prod(const t_vector lhs, const t_vector rhs, t_vector res);
float       	coord_dot_prod(const t_vector lhs, const t_vector rhs);
void			coord_normalize(const t_vector vector, t_vector dest);

#endif
