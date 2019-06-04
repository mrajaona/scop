/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:26:36 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:26:37 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_DATA_H
# define SET_DATA_H

# include "glew_inc.h"

# include "data_struct.h"

# include "use_model.h"

# include "vector.h"
# include "coord.h"
# include "mat4_transform.h"

# include "lookat.h"
# include "perspective.h"

void			set_model(t_data *data);
void			set_light(t_data *data);
void			set_view(t_data *data);
void			set_proj(t_data *data);

#endif
