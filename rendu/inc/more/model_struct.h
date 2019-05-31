#ifndef MODEL_STRUCT_H
# define MODEL_STRUCT_H

# include <stdio.h>
# include "list.h"

# include "vector.h"

/*
** name		: material name
** Ns		: specular exponent
** Ka		: ambient color
** Kd		: diffuse color
** Ks		: specular color
** Ni		: optical_density (index of refraction)
** d		: dissolve (opacity)
** ** Tr	: transparency = 1 - d
** illum	: illumination model
** ** 0. Color on and Ambient off
** ** 1. Color on and Ambient on
** ** 2. Highlight on
** ** 3. Reflection on and Ray trace on
** ** 4. Transparency: Glass on, Reflection: Ray trace on
** ** 5. Reflection: Fresnel on and Ray trace on
** ** 6. Transparency: Refraction on, Reflection: Fresnel off and Ray trace on
** ** 7. Transparency: Refraction on, Reflection: Fresnel on and Ray trace on
** ** 8. Reflection on and Ray trace off
** ** 9. Transparency: Glass on, Reflection: Ray trace off
** ** 10. Casts shadows onto invisible surfaces
*/


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