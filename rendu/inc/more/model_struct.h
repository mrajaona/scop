#ifndef MODEL_STRUCT_H
# define MODEL_STRUCT_H

# include <stdio.h>
# include "list.h"

# include "vector.h"

typedef struct	s_material
{
	char		*name;
	float		Ns;
	t_vector	Ka;
	t_vector	Kd;
	t_vector	Ks;
	float		Ni;
	float		d;
	int			illum;
}				t_material;

/*
** float	tmp_vertices[3]
** GLuint	faces[3]
*/

typedef struct	s_model
{
	t_list		*vertices;
	t_list		*faces;
	size_t		nfaces;
	char		*res_folder;
	FILE		*mtl_fp;
	t_material	material;
}				t_model;

#endif