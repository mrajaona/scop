/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glew_inc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:26:05 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:26:07 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLEW_INC_H
# define GLEW_INC_H

# ifdef __APPLE__
/*
** #  define GLEW_STATIC
** #  define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
** #  define GLFW_INCLUDE_GLCOREARB
** #  include "glew.h"
*/
# else
#  define GLEW_STATIC
#  include <GL/glew.h>
# endif

#endif
