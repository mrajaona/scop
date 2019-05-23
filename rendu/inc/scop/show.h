#ifndef SHOW_H
# define SHOW_H

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

# include <unistd.h> // sleep

# include "data_struct.h"

# include "coord.h"

# include "mat4.h"
# include "vector.h"

# include "mat4_transform.h"
# include "mat4_rotate.h"

# include "angle.h"

void			show(const t_data *data);

#endif
