/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:47 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 19:06:21 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include "vector.h"
# include <stdbool.h>

# define WIDTH	1920
# define HEIGHT 1080
# define R 50
# define NAME "AlCu"

typedef struct s_alcu
{
	t_vector	board;
	bool		*need_win;
	size_t		pos;
}	t_alcu;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		background;
	t_img		img;
	t_alcu		alcu;
	int			selected;
	bool		need_clear;
	bool		user_play;
}	t_mlx;


int		parsing(t_vector *s_tab, int ac, char **av);
int		ft_atoi(const char *str);
char	*get_next_line(int fd);
void	ft_putnbr_fd(int n, int fd);
void	print_tab(t_vector *vector);
void	ft_error(char *err);
int		get_user_input(int max);
int		init_need_win(t_alcu *alcu);
int		get_loose(int value);
int		get_win(int value);
void	routine(t_alcu *alcu);

void	put_4_pixel(t_img *img, int x, int y, int color);
void	put_pixel(t_img *img, int x, int y, unsigned int color);
void	mlx_hooks(t_mlx *data);
int		mlx_init_mlx(t_mlx *data);
int		mlx_destroy_mlx(t_mlx *data);
int		display(t_mlx *data);
int		keypress_hook(int key, t_mlx *data);
void	remove_in_line(int remove_nb, t_alcu *alcu);
int		get_ai_play(t_alcu *alcu);

#endif