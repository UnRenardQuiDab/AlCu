/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:22:09 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 18:12:09 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdio.h>

void	remove_in_line(int remove_nb, t_alcu *alcu)
{
	alcu->board.tab[alcu->pos] -= remove_nb;
	if (alcu->board.tab[alcu->pos] <= 0)
		alcu->pos--;
}

void	routine(t_alcu *alcu)
{
	int	remove_nb;

	while (alcu->board.tab[0] > 0)
	{
		print_tab(&alcu->board);
		if (alcu->need_win.tab[alcu->pos] == 1)
			remove_nb = get_win(alcu->board.tab[alcu->pos]);
		else
			remove_nb = get_loose(alcu->board.tab[alcu->pos]);
		remove_in_line(remove_nb, alcu);
		printf("IA took %d\n", remove_nb);
		print_tab(&alcu->board);
		remove_nb = get_user_input(alcu->board.tab[alcu->pos]);
		if (remove_nb == -1)
			return ;
		remove_in_line(remove_nb, alcu);
	}
}
