#ifndef MODEL_H
# define MODEL_H

typedef struct	t_list
{
	void	*data;
	t_list	*next;
}				t_list;

void			free_list(t_list *list);
t_list			*new_elem(t_list *list);

typedef struct	s_model
{
	t_list		*faces; 		// unsigned int	faces[3]; // vert / uv / norm
	t_list		*tmp_vertices;	// float tmp_vertices[3];
	t_list		*tmp_uvs;		// float tmp_uvs[2];
	t_list		*tmp_normals;	// float tmp_normals[3];
}				t_model;

int				load_model(const char *path);

#endif
