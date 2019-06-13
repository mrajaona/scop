/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mtl_check.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:11:22 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/13 10:11:22 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MTL_CHECK_H
# define READ_MTL_CHECK_H

# include <string.h>

# include "model_struct.h"

int	check_vector(int *ret, const char *type, FILE *fp, t_material *material);
int	check_float(int *ret, const char *type, FILE *fp, t_material *material);
int	check_illum(int *ret, const char *type, FILE *fp, t_material *material);

#endif
