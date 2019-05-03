#ifndef COMMON_H
# define COMMON_H

# include "glfw.h"

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
}			   t_data;

#endif
