/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:47 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 16:35:10 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

#include "vector.h"

typedef struct s_alcu
{
	t_vector	board;
	t_vector	need_win;
	size_t		pos;
}	t_alcu;


int		parsing(t_vector *s_tab, int ac, char **av);
int		ft_atoi(const char *str);
char	*get_next_line(int fd);
void	print_tab(t_vector *vector);
void	ft_error(char *err);
int		get_user_input(int max);
int		init_need_win(t_alcu *alcu);
int		get_loose(int value);
int		get_win(int value);
void	routine(t_alcu *alcu);

#endif