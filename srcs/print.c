/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:46:54 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 12:12:42 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <unistd.h>

int	get_max(t_vector *vector)
{
	size_t	i;
	int		max;

	i = 0;
	max = -1;
	while (i < vector->len)
	{
		if (vector->tab[i] > max)
			max = vector->tab[i];
		i++;
	}
	return (max);
}

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
	int		max;

	i = 0;
	max = get_max(vector);
	while (i < vector->len)
	{
		if (vector->tab[i] > 0)
			print_line(vector->tab[i], max);
		i++;
	}
}
