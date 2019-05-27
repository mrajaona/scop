/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:25:37 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:25:38 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYS_H
# define ARRAYS_H

# include "glew_inc.h"
# include "glfw_inc.h"

void			ebo(GLuint *ebo, const GLuint *elements, size_t size);
void			vao(GLuint *vao);
void			vbo(GLuint *vbo, size_t size);

#endif
