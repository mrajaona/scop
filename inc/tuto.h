#ifndef TUTO_H
# define TUTO_H

# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# define GLEW_STATIC
# include <GL/glew.h>
# include <GLFW/glfw3.h>

# include <stdlib.h>
# include <stdio.h>

# include "SOIL.h"

# define N_TEXTURES 2

typedef struct	s_data
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
}				t_data;

void	glfw_init(GLFWwindow **window);

void 	vbo(GLuint *vbo);
void	vao(GLuint *vao);
void	ebo(GLuint *ebo);
void	tex(GLuint *tex, t_data *scop);
void	shader_program(GLuint *shaderProgram, t_data *scop);
void	show(t_data *scop);

void	ft_exit(t_data *scop, int status);

#endif
