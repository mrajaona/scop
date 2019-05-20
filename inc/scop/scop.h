#ifndef SCOP_H
# define SCOP_H

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

/* GLFW */
# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# include <GLFW/glfw3.h>
/* GLFW */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> // sleep
# include <string.h>
# include <errno.h>

# include "SOIL.h"

# include "mat4.h"
# include "vector.h"
# include "coord.h"

# include "mat4_transform.h"
# include "mat4_rotate.h"

# include "perspective.h"
# include "lookat.h"

# include "angle.h"

typedef struct	s_shader
{
	GLuint	program;
	GLuint	vertex;
	GLuint	fragment;
}				t_shader;

typedef struct	s_model
{
	t_mat4		mat;
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;	
}				t_model;

# define N_TEXTURES 2

typedef struct	s_data
{
	GLFWwindow	*window;
	t_shader	shader;
	GLuint		textures[N_TEXTURES];
	t_mat4		view;
	t_mat4		proj;
	t_model		model;
}				t_data;

# define TEX_FORMAT GL_RGB

# define BMP_MAGIC "\x42\x4D"
# define PNG_MAGIC "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A"
# define JPG_MAGIC "\xFF\xD8\xFF"

#endif