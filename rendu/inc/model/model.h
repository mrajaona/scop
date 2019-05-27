/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:25:22 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:25:25 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H

# include "glew_inc.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "data_struct.h"
# include "arrays.h"

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

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

# define N_DATA_PER_VERTICE 3
# define N_VERTICES_PER_FACE 3

int				load_model(const char *path, t_data *data);

#endif
