/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj_mtl.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:47:29 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/13 10:47:30 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_OBJ_MTL_H
# define READ_OBJ_MTL_H

# include <stdio.h>

# include "model_struct.h"
# include "read_mtl.h"

int	read_mtllib(FILE *fp, t_model *model);
int	read_usemtl(FILE *fp, t_model *model);

#endif
