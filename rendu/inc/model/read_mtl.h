/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mtl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:52:34 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 10:52:35 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MTL_H
# define READ_MTL_H

# include <string.h>

# include "model_struct.h"
# include "read_mtl_check.h"

void	open_mtl(const char *name, t_model *model);
void	use_mtl(const char *name, FILE *fp, t_material *material);

#endif
