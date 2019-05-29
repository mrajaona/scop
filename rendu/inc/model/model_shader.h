/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_shader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:26:47 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:26:48 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_SHADER_H
# define MODEL_SHADER_H

# include "glew_inc.h"

# include <stdio.h>

# include "shader_struct.h"
# include "model.h"

int	model_shader_init(t_shader *shader);

#endif
