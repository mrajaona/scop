/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:26:54 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:26:55 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_STRUCT_H
# define SHADER_STRUCT_H

# include "glfw_inc.h"

typedef struct	s_shader
{
	GLuint	program;
	GLuint	vertex;
	GLuint	fragment;
}				t_shader;

#endif
