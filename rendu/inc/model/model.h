#ifndef MODEL_H
# define MODEL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_model
{
	t_list		*faces; 		// unsigned int	faces[3]; // vert / uv / norm
	t_list		*vertices;		// float tmp_vertices[3];
}				t_model;

float			*load_model(const char *path);

#endif
