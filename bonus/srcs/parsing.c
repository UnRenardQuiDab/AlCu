/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:22:18 by fsariogl          #+#    #+#             */
/*   Updated: 2024/03/31 19:56:01 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/vector.h"
#include "../includes/alcu.h"
#include <stdlib.h>
#include <fcntl.h>

static int	parse_error(t_vector *s_tab, char *buff)
{
	vector_free(s_tab);
	close(s_tab->fd);
	if (buff)
		free(buff);
	ft_error("ERROR\n");
	return (-1);
}

int	parsing(t_vector *s_tab, int ac, char **av)
{
	char	*buff = NULL;

	vector_init(s_tab);
	s_tab->fd = 0;
	if (ac > 1)
	{
		s_tab->fd = open(av[1], O_RDONLY);
		if (s_tab->fd < 0)
			return (parse_error(s_tab, buff));
	}
	while ((buff = get_next_line(s_tab->fd)) != NULL)
	{
		if (buff == NULL && s_tab->len == 0)
			return (parse_error(s_tab, buff));
		else if (buff[0] == '\n')
			break ;
		for (int i = 0; buff[i] && buff[i] != '\n'; i++)
			if (buff[i] < '0' || buff[i] > '9')
				return (parse_error(s_tab, buff));
		vector_add(s_tab, ft_atoi(buff));
		if (ft_atoi(buff) < 1 || ft_atoi(buff) > 10000)
			return (parse_error(s_tab, buff));
		free(buff);
	}
	free(buff);
	if (s_tab->len == 0)
		return (parse_error(s_tab, NULL));
	close(s_tab->fd);
	return (0);
}