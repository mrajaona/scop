#ifndef TUTO_H
# define TUTO_H

# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# define GLEW_STATIC
# include <GL/glew.h>
# include <GLFW/glfw3.h>

void 	vbo();
void	shader_program();
void	vao();

#endif
