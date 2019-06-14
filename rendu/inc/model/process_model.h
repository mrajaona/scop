/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_model.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:52:22 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 10:52:23 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_MODEL_H
# define PROCESS_MODEL_H

# include "model_struct.h"
# include "data_struct.h"

# include "model.h"
# include "use_model.h"

# include "vbo.h"
# include "process_model_attribs.h"

int				process_model(const t_model *model, t_data *data);

#endif
