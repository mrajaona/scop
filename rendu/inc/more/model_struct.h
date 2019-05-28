#ifndef MODEL_STRUCT_H
# define MODEL_STRUCT_H

# include <stdio.h>
# include "list.h"

typedef struct	s_material
{
	
}				t_material;

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
	FILE		*mtl_fp;
	t_material	material;
}				t_model;

#endif