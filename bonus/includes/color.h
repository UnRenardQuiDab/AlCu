/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:08:09 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 14:08:19 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef union u_color
{
	uint32_t	color;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}	t_color;

typedef struct s_grad_3
{
	t_color	start;
	t_color	mid;
	t_color	end;
}	t_grad_3;

t_color		color(unsigned char a, unsigned char r,
				unsigned char g, unsigned char b);
t_color		color_hex(unsigned int hexa);
t_color		color_grad2(t_color start, t_color end, int value);
t_color		color_grad3(t_grad_3 grad, int value);
t_grad_3	create_grad3(t_color start, t_color mid, t_color end);
int			get_rand_color(t_color *color);
t_grad_3	get_rand_grad(void);

#endif