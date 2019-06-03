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

# include <stdlib.h>

# include "glew_inc.h"

# include "data_struct.h"

# include "model_struct.h"
# include "list.h"

# include "read_model.h"
# include "process_model.h"

# define N_DATA_PER_VERTICE 8
# define N_VERTICES_PER_FACE 3

int			load_model(const char *path, t_data *data);
void		free_model(t_model **model);

#endif
