#ifndef SCENE_H
# define SCENE_H

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

# include "vector.h"
# include "coord.h"
# include "angle.h"
# include "lookat.h"
# include "perspective.h"
# include "data.h"

void		set_scene(t_data *data);

#endif