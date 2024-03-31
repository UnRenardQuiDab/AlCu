/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:22:09 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 12:04:48 by bwisniew         ###   ########.fr       */
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
	write(1, "IA took ", 8);
	ft_putnbr_fd(result, 1);
	write(1, "\n", 1);
	return (result);
}

void	remove_in_line(int remove_nb, t_alcu *alcu)
{
	alcu->board.tab[alcu->pos] -= remove_nb;
	if (alcu->board.tab[alcu->pos] <= 0)
		alcu->pos--;
}

void	routine(t_alcu *alcu)
{
	int		remove_nb;
	bool	user_play;

	user_play = false;
	while (alcu->board.tab[0] > 0)
	{
		print_tab(&alcu->board);
		if (user_play)
		{
			remove_nb = get_user_input(alcu->board.tab[alcu->pos]);
			if (remove_nb == -1)
				return ;
		}
		else
			remove_nb = get_ai_play(alcu);
		remove_in_line(remove_nb, alcu);
		user_play = !user_play;
	}
	if (!user_play)
		write(1, "AI is the winner! Try again!\n", 29);
	else
		write(1, "You are the winner! Congratulations!\n", 37);
}
