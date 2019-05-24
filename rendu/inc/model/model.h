#ifndef MODEL_H
# define MODEL_H

# include "glew_inc.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "data_struct.h"

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_model
{
	t_list		*vertices;		// float tmp_vertices[3];
	size_t		nvertices;
	t_list		*faces; 		// GLuint	faces[3];
	size_t		nfaces;
}				t_model;

int				load_model(const char *path, t_data *data);

#endif
