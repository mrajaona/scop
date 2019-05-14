#ifndef DATA_H
# define DATA_H

/* GLFW */
# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif
/* GLFW */

# include "texture.h"
# include "shader.h"
# include "mat4.h"
# include "model.h"

typedef struct	s_data
{
	GLFWwindow	*window;
	t_shader	shader;
	GLuint		textures[N_TEXTURES];
	t_mat4		view;
	t_mat4		proj;
	t_model		model;
	t_model		floor; // tuto
}				t_data;

void	data_exit(t_data *data, const int status);
void	data_del(t_data *data);
void	data_clr(t_data *data);
void	data_init(t_data *data);

#endif