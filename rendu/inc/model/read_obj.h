/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:52:46 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 10:52:46 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_OBJ_H
# define READ_OBJ_H

# include <stdio.h>

# include "glfw_inc.h"

# include "model_struct.h"
# include "read_mtl.h"

int	read_v(FILE *fp, t_model *model);
int	read_f(FILE *fp, t_model *model);
int	read_s(FILE *fp, t_model *model);
int	read_mtllib(FILE *fp, t_model *model);
int	read_usemtl(FILE *fp, t_model *model);

#endif
