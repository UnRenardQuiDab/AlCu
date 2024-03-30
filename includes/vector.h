/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:22:04 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 11:51:19 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>

# define START_SIZE 4

typedef struct s_vector
{
	int		*tab;
	size_t	len;
	size_t	memory;
}	t_vector;

int		vector_add(t_vector *vector, int value);
void	vector_free(t_vector *vector);
void	vector_init(t_vector *vector);

#endif