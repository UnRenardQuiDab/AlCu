/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:46:54 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 18:49:32 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <unistd.h>

void	print_line(int value, int max)
{
	int	i;

	i = 0;
	while (i < max - value)
	{
		write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i < value)
	{
		write(1, " |", 2);
		i++;
	}
	write(1, "\n", 1);
}

void	print_tab(t_vector *vector)
{
	size_t	i;

	i = 0;
	while (i < vector->len)
	{
		if (vector->tab[i] > 0)
			print_line(vector->tab[i], vector->max);
		i++;
	}
}
