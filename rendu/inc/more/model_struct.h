#ifndef MODEL_STRUCT_H
# define MODEL_STRUCT_H

# include "list.h"

/*
** float	tmp_vertices[3]
** GLuint	faces[3]
*/

typedef struct	s_model
{
	t_list		*vertices;
	size_t		nvertices;
	t_list		*faces;
	size_t		nfaces;
}				t_model;

#endif