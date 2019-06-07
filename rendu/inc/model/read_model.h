/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_model.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:52:13 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 10:52:14 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MODEL_H
# define READ_MODEL_H

# include <string.h>

# include "model.h"

# include "read_obj.h"
# include "read_mtl.h"

t_model		*read_model(const char *path);

#endif
