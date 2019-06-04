/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ext.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:26:22 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:26:22 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_EXT_H
# define INIT_EXT_H

# include "glew_inc.h"
# include "glfw_inc.h"

# include <stdio.h>
# include <stdlib.h>

# include "perspective.h"

void			glfw_init(GLFWwindow **window);
void			glew_init(void);

#endif
