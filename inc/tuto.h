#ifndef TUTO_H
# define TUTO_H

# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# define GLEW_STATIC
# include <GL/glew.h>
# include <GLFW/glfw3.h>

# include <unistd.h>
# include <stdio.h>

typedef struct	s_data
{
	GLuint vertexBuffer;
	GLuint	vbo;
	GLuint	vao;	
	GLuint	shaderProgram;
	GLint	uniColor;
}				t_data;


void 	vbo(GLuint *vbo);
void	vao(GLuint *vao);
void	shader_program(GLuint *shaderProgram;);

#endif
