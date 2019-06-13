/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbo.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:13:22 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/13 11:13:23 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VBO_H
# define VBO_H

# include "glfw_inc.h"

# include "model_struct.h"
# include "data_struct.h"

# include "model.h"
# include "use_model.h"

# include "vector.h"
# include "vector_op.h"
# include "coord.h"
# include "coord_op.h"

# include "process_model_attribs.h"

typedef struct	s_triangle
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	t_coord		normal;
}				t_triangle;

int				vbo(GLuint *vbo, const t_model *model);

#endif
