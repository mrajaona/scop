/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_model_attribs.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:55:44 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/13 10:55:45 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_MODEL_ATTRIBS_H
# define PROCESS_MODEL_ATTRIBS_H

# include "glfw_inc.h"

# include "model_struct.h"
# include "data_struct.h"

# include "model.h"

# define NDATA N_DATA_PER_VERTICE

void		set_attribs(const GLuint program, const t_model *model);

#endif
