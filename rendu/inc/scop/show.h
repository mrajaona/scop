/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:27:02 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:27:02 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_H
# define SHOW_H

# include <unistd.h>

# include "data_struct.h"

# include "coord.h"

# include "mat4.h"
# include "vector.h"

# include "mat4_transform.h"
# include "mat4_rotate.h"

# include "angle.h"

# include "model.h"
# include "use_model.h"

# define MV_VALUE 0.1

typedef struct	s_edit
{
	t_mat4		model;
	t_vector	to_center;
	t_vector	to_origin;
	GLint		uniform;
}				t_edit;

void			show(const t_data *data);

#endif
