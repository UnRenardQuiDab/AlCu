/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:47 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 12:28:03 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

#include "vector.h"

void    parsing(t_vector *tab);
int     ft_atoi(const char *str);
char	*get_next_line(int fd);
void	print_tab(t_vector *vector);

#endif