/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:22:18 by fsariogl          #+#    #+#             */
/*   Updated: 2024/03/30 17:32:31 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include "../includes/alcu.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

static int	parse_error(t_vector *s_tab)
{
	vector_free(s_tab);
	ft_error("ERROR\n");
	return (-1);
}

int	parsing(t_vector *s_tab, int ac, char **av)
{
	char	*buff;
	int		fd = 0;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
	}
	vector_init(s_tab);
	while ((buff = get_next_line(fd)) != NULL && buff[0] != '\n')
	{
		for (int i = 0;buff[i] && buff[i] != '\n'; i++)
			if (buff[i] < '0' || buff[i] > '9')
				return (parse_error(s_tab));
		vector_add(s_tab, ft_atoi(buff));
		free(buff);
	}
	free(buff);
	return (0);
}