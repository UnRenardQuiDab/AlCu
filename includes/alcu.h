/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:47 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 14:33:24 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

#include "vector.h"

int    parsing(t_vector *s_tab, int ac, char **av);
int     ft_atoi(const char *str);
char	*get_next_line(int fd);
void	print_tab(t_vector *vector);

#endif