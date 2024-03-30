/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:47 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 14:26:59 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

#include "vector.h"

void    parsing(t_vector *tab);
int     ft_atoi(const char *str);
char	*get_next_line(int fd);
void	print_tab(t_vector *vector);
void	ft_error(char *err);
int		get_user_input(int max);

#endif