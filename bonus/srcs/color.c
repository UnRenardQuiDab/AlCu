/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:09:55 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 14:10:03 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color(unsigned char a, unsigned char r,
				unsigned char g, unsigned char b)
{
	t_color	color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	color_hex(unsigned int hexa)
{
	t_color	color;

	color.color = hexa;
	return (color);
}

t_color	color_grad2(t_color start, t_color end, int value)
{
	t_color	color;
	double	percent;

	percent = (double)value / UINT8_MAX;
	color.r = (1 - percent) * start.r + percent * end.r;
	color.g = (1 - percent) * start.g + percent * end.g;
	color.b = (1 - percent) * start.b + percent * end.b;
	color.a = (1 - percent) * start.a + percent * end.a;
	return (color);
}

t_color	color_grad3(t_grad_3 grad, int value)
{
	if (value * 2 < UINT8_MAX)
		return (color_grad2(grad.start, grad.mid, value * 2));
	return (color_grad2(grad.mid, grad.end, (value - UINT8_MAX / 2) * 2));
}

t_grad_3	create_grad3(t_color start, t_color mid, t_color end)
{
	t_grad_3	grad;

	grad.start = start;
	grad.mid = mid;
	grad.end = end;
	return (grad);
}