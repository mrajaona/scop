#ifndef SET_DATA_H
# define SET_DATA_H

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

# include "data_struct.h"

# include "vector.h"
# include "coord.h"

# include "lookat.h"
# include "perspective.h"

# include "angle.h"

void 			set_model(t_data *data);
void			set_view(t_data *data);
void			set_proj(t_data *data);

#endif
