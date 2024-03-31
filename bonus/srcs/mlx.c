/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:07:22 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 20:22:09 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "alcu.h"
#include <X11/X.h>
#include <stdlib.h>

void	mlx_hooks(t_mlx *data)
{
	mlx_loop_hook(data->mlx, display, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, mlx_loop_end, data->mlx);
	mlx_hook(data->win, KeyPress, KeyPressMask, keypress_hook, data);
}

void	put_4_pixel(t_img *img, int x, int y, int color)
{
	put_pixel(img, x, y, color);
	put_pixel(img, x + 1, y + 1, color);
	put_pixel(img, x, y + 1, color);
	put_pixel(img, x + 1, y, color);
}

void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (int)(y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mlx_init_mlx(t_mlx *data)
{
	data->selected = get_ai_play(&data->alcu);
	data->mlx = mlx_init();
	data->need_clear = true;
	data->user_play = false;
	if (!data->mlx)
		return (-1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, NAME);
	if (!data->win)
		return (-1);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
		return (-1);
	data->background.img = mlx_xpm_file_to_image(data->mlx, "background.xpm", &(data->background.width), &(data->background.height));
	if (!data->background.img)
		return (-1);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&(data->img.bits_per_pixel), &(data->img.line_length),
			&(data->img.endian));
	if (!data->img.addr)
		return (-1);
	data->background.addr = mlx_get_data_addr(data->background.img,
			&(data->background.bits_per_pixel), &(data->background.line_length),
			&(data->background.endian));
	if (!data->background.addr)
		return (-1);
	return (0);
}

int	mlx_destroy_mlx(t_mlx *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->background.img)
		mlx_destroy_image(data->mlx, data->background.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	return (0);
}
