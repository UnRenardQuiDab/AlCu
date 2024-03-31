/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:54:02 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 12:01:57 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool	start_is_win(int value)
{
	return ((value - 1) % 4 != 0);
}

bool	start_is_loose(int value)
{
	return ((value % 4) != 0);
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

	alcu->need_win = malloc(alcu->board.len * sizeof(bool));
	if (!alcu->need_win)
		return (1);
	alcu->need_win[0] = true;
	alcu->pos = alcu->board.len - 1;
	i = 1;
	while (i < alcu->board.len)
	{
		if (alcu->need_win[i - 1] == true)
		{
			if (start_is_win(alcu->board.tab[i - 1]) == 0)
				alcu->need_win[i] = false;
			else
				alcu->need_win[i] = true;
		}
		else if (alcu->need_win[i - 1] == false)
		{
			if (start_is_loose(alcu->board.tab[i - 1]) == 0)
				alcu->need_win[i] = false;
			else
				alcu->need_win[i] = true;
		}
		i++;
	}
	return (0);
}
