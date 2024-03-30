/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:54:02 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 18:08:13 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdbool.h>

bool	start_is_win(int value)
{
	return ((value % 4) - 1);
}

int	get_win(int value)
{
	int	nb;

	nb = (value % 4) - 1;
	if (nb == 0)
		return 1;
	if (nb == -1)
		return (3);
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
	alcu->pos = alcu->board.len - 1;
	i = 1;
	while (i < alcu->board.len)
	{
		if ((start_is_win(alcu->board.tab[i - 1])
				&& alcu->need_win.tab[i - 1] == 1)
			|| (!start_is_win(alcu->board.tab[i - 1])
				&& alcu->need_win.tab[i - 1] == 0))
			if (vector_add(&alcu->need_win, true) == 1)
				return (1);
		if ((!start_is_win(alcu->board.tab[i - 1])
				&& alcu->need_win.tab[i - 1] == 1)
			|| (start_is_win(alcu->board.tab[i - 1])
				&& alcu->need_win.tab[i - 1] == 0))
			if (vector_add(&alcu->need_win, false) == 1)
				return (1);
		i++;
	}
	return (0);
}
