/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:25:45 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 19:47:23 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "color.h"
#include "mlx.h"
#include <stdio.h>

unsigned int mlx_get_pixel(int x, int y, t_img *img)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    return (*(unsigned int*)dst);
}

void	fill_window(t_mlx *data)
{
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			put_pixel(&(data->img), x, y, mlx_get_pixel(x, y, &data->background));
			y++;
		}
		x++;
	}
}

double	euclidian_distance(int x1, int y1, int x2, int y2)
{
	return (((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

void	display_circle(int x, int y, int r, t_mlx *data, t_color p_color)
{
	int x_p;
	int y_p;

	x_p = x - r;
	while (x_p <= x + r)
	{

		y_p = y - r;
		while (y_p <= y + r)
		{
			if (euclidian_distance(x_p, y_p, x, y) <= r * r && x_p >= 0 && x_p <= WIDTH && y_p >= 0 && y_p <= HEIGHT)
			{
				put_pixel(&(data->img), x_p, y_p, color_grad2(p_color, color(0, 0, 0, 0), (euclidian_distance(x_p, y_p, x, y) / (double)R * R * 2)).color);
			}
			y_p++;
		}
		x_p++;
	}
}

bool	is_selected(t_mlx *data, int i)
{
	int	size;

	size = data->alcu.board.tab[data->alcu.pos];
	if (data->selected == 1)
		return (i == size / 2);
	else if (data->selected == 2)
		return (i == size / 2 || i == (size / 2) - 1);
	else if (data->selected == 3)
		return (i == size / 2 || i == (size / 2) + 1 || i == (size / 2) - 1);
	return (false);
}

void	display_line(int y, int	nb, t_mlx *data, bool colored)
{
	int	x_offset;
	int	r = 50;

	x_offset = WIDTH / 2 - (nb * r * 2) / 2 + r;
	int i = 0;
	while (i < nb)
	{
		if (colored && is_selected(data, i) && data->user_play == false)
			display_circle(x_offset, y, 45, data, color(255, 0, 0, 255));
		else if (colored && is_selected(data, i))
			display_circle(x_offset, y, 45, data, color(255, 0, 255, 0));
		else
			display_circle(x_offset, y, 45, data, color(255, 255, 255, 255));
		x_offset += r * 2;
		i++;
	}
}

int	display(t_mlx *data)
{
	size_t	i;
	int		y;

	if (data->need_clear)
	{
		fill_window(data);
		data->need_clear = false;
		return (0);
	}
	i = data->alcu.pos + 1;
	y = HEIGHT - R * 4;
	while (i > 0)
	{
		display_line(y, data->alcu.board.tab[i - 1], data, data->alcu.pos == i - 1);
		y -= R * 2;
		i--;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
