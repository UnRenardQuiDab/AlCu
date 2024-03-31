/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:22:09 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 20:01:01 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdio.h>

int	get_ai_play(t_alcu *alcu)
{
	int	result;

	if (alcu->need_win[alcu->pos] == 1)
		result = get_win(alcu->board.tab[alcu->pos]);
	else
		result = get_loose(alcu->board.tab[alcu->pos]);
	return (result);
}

void	remove_in_line(int remove_nb, t_alcu *alcu)
{
	alcu->board.tab[alcu->pos] -= remove_nb;
	if (alcu->board.tab[alcu->pos] <= 0)
		alcu->pos--;
}