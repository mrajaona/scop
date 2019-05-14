#ifndef TEST_H
# define TEST_H

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

/* SOIL */
# include "SOIL.h" // tmp

/* SOIL */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# include "../matrix/mat4.h"
# include "../matrix/vector.h"
# include "../matrix/vector_op.h"
# include "../matrix/angle.h"
# include "../matrix/lookat.h"
# include "../matrix/perspective.h"

# define FAILURE 0
# define SUCCESS 1

# define BYTES_PER_PIXEL 3
# define TEX_FORMAT GL_RGB

# define BMP_MAGIC "\x42\x4D"
# define PNG_MAGIC "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A"
# define JPG_MAGIC "\xFF\xD8\xFF"

typedef struct	s_model
{
	t_mat4		mat;
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;	
}				t_model;

typedef struct	s_shader
{
	GLuint	program;
	GLuint	vertex;
	GLuint	fragment;
}				t_shader;

# define N_TEXTURES 2

typedef struct	s_data
{
	void		*data;
	t_shader	shader;
	GLuint		textures[N_TEXTURES];
	t_mat4		view;
	t_mat4		proj;
	t_model		model;
	t_model		floor; // tuto
}				t_data;

/* functions */

	void	model_del(t_model *model);
	void	model_clr(t_model *model);
	void	set_view(t_data *scop);
	void	set_proj(t_data *scop);
	void		set_scene(t_data *scop);
	unsigned char	*load(const char *path, int *width, int *height);
	int						load_img(const char *path);
	void	bw_checkerboard(void);
	void	set_TexParameter(const int loaded);
	void	texture_init(GLuint textures[N_TEXTURES], const GLuint shader);
	int	shader_status(const GLuint shader);
	int	vertex_shader(t_shader *shader);
	int	fragment_shader(t_shader *shader);
	void	vertex_attribute_array(const GLuint shaderProgram);
	int	shader_init(t_shader *shader);
	void	scop_exit(t_data *scop, const int status);
	void	scop_del(t_data *scop);
	void	scop_clr(t_data *scop);
	void	scop_init(t_data *scop);
	void	glfw_init();
	void	glew_init();
	void	init(t_data *scop);

#endif