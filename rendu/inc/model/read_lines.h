/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:35:35 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/13 10:35:36 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_LINES_H
# define READ_LINES_H

# include <string.h>

# include "model.h"

# include "read_obj.h"
# include "read_obj_mtl.h"

void	read_lines(FILE *fp, t_model **model);

#endif
