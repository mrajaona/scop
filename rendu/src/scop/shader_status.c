/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:15:45 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 11:15:45 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_status.h"

#include <stdlib.h>

int		shader_status(const GLuint shader)
{
	GLint status;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		fprintf(stderr, "shader init error\n");
		fflush(stderr);
		return (0);
	}
	return (1);
}
