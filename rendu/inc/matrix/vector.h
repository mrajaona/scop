/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:24:36 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:24:37 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdio.h>

typedef float	t_vector[4];
typedef float	*t_vector_ptr;

// debug
void			vector_print(const t_vector src);

void			clear_vector(t_vector vec);
void			vector_eq(t_vector dst, const t_vector src);

#endif
