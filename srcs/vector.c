/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:26:02 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 11:41:54 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*mem_dest;

	if (dest == src)
		return (dest);
	mem_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		mem_dest[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

int	vector_realoc(t_vector *vector)
{
	int	*new_tab;

	if (vector->memory == 0)
		vector->memory = START_SIZE;
	else
		vector->memory *= 2;
	new_tab = malloc(sizeof(int) * vector->memory);
	if (!new_tab)
	{
		if (vector->tab)
			free(vector->tab);
		return (1);
	}
	ft_memcpy(new_tab, vector->tab, vector->len);
	if (vector->tab)
		free(vector->tab);
	vector->tab = new_tab;
	return (0);
}

int	vector_add(t_vector *vector, int value)
{
	if (vector->len == vector->memory)
		if (vector_realoc(vector))
			return (1);
	vector->tab[vector->len] = value;
	vector->len++;
	return (0);
}

void	vector_init(t_vector *vector)
{
	vector->len = 0;
	vector->memory = 0;
	vector->tab = NULL;
}

void	vector_free(t_vector *vector)
{
	if (vector->tab)
		free(vector->tab);
	vector_init(vector);
}
