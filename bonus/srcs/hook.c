/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:40:39 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 18:57:51 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "mlx.h"
#define XK_MISCELLANY
#define XK_LATIN1
#include <X11/keysymdef.h>
#include <X11/X.h>
#include <stdio.h>

void	selected_add(t_mlx *data)
{
	if (data->selected + 1 <= 3 && data->selected + 1 <= data->alcu.board.tab[data->alcu.pos] && data->user_play)
		data->selected++;
}

void	selected_remove(t_mlx *data)
{
	if (data->selected - 1 > 0  && data->user_play)
		data->selected--;
}

int	keypress_hook(int key, t_mlx *data)
{
	if (key == XK_Escape)
		mlx_loop_end(data->mlx);
	if (key == XK_Up)
		selected_add(data);
	if (key == XK_Down)
		selected_remove(data);
	if (key == XK_Return)
	{
		data->need_clear = true;
		remove_in_line(data->selected, &data->alcu);
		if (data->alcu.board.tab[0] <= 0)
		{
			if (data->user_play)
				write(1, "AI is the winner! Try again!\n", 29);
			else
				write(1, "You are the winner! Congratulations!\n", 37);
			mlx_loop_end(data->mlx);
		}
		else if (data->user_play)
		{
			write(1, "User took ", 10);
			ft_putnbr_fd(data->selected, 1);
			write(1, "\n", 1);
			data->selected = get_ai_play(&data->alcu);
		}
		else
		{
			write(1, "IA took ", 8);
			ft_putnbr_fd(data->selected, 1);
			write(1, "\n", 1);
			data->selected = 1;
		}
		data->user_play = !data->user_play;
	}
	return (0);
}
