/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:35 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 18:12:17 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "alcu.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_alcu	alcu;

	if (parsing(&alcu.board, ac, av) == -1)
		return (-1);
	if (init_need_win(alcu) == -1)
	routine(&alcu);
	vector_free(&alcu.board);
	vector_free(&alcu.need_win);
	return (0);
}
