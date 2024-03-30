/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:54:02 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 19:30:26 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdbool.h>
#include <stdio.h>

bool	start_is_win(int value)
{
	return ((value - 1) % 4);
}

bool	start_is_loose(int value)
{
	return ((value % 4) == 0);
}

int	get_win(int value)
{
	int	nb;

	nb = (value - 1) % 4;
	if (nb == 0)
		return (1);
	return (nb);
}

int	get_loose(int value)
{
	int	nb;

	nb = value % 4;
	if (nb == 0)
		return (1);
	return (nb);
}

int	init_need_win(t_alcu *alcu)
{
	size_t	i;

	vector_init(&alcu->need_win);
	vector_add(&alcu->need_win, true);
	printf("1");
	alcu->pos = alcu->board.len - 1;
	i = 1;
	while (i < alcu->board.len)
	{
		if ()
		{}
		i++;
	}
	printf("\n");
	return (0);
}
