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


# define BYTES_PER_PIXEL 3








/* functions */

	void	model_del(t_model *model);
	void	model_clr(t_model *model);
	void	set_view(t_data *data);
	void	set_proj(t_data *data);
	void		set_scene(t_data *data);
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
	void	data_exit(t_data *data, const int status);
	void	data_del(t_data *data);
	void	data_clr(t_data *data);
	void	data_init(t_data *data);
	void	glfw_init();
	void	glew_init();
	void	init(t_data *data);

#endif