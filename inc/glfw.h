#ifndef GLFW_H
# define GLFW_H

# ifdef __APPLE__
#  define GLFW_INCLUDE_GLCOREARB
# endif

# include <GLFW/glfw3.h>
# include <stdio.h>

# include "common.h"
# include "error.h"

void    glfw_init(GLFWwindow **window);

#endif