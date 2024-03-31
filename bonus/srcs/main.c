/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:35 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 15:20:12 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "mlx.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_mlx	data;

	if (parsing(&data.alcu.board, ac, av) == -1)
		return (-1);
	if (init_need_win(&data.alcu) == -1)
	{
		vector_free(&data.alcu.board);
		return (-1);
	}
	if (mlx_init_mlx(&data) == -1)
		return (mlx_destroy_mlx(&data));
	mlx_hooks(&(data));
	mlx_loop(data.mlx);
	mlx_destroy_mlx(&data);
	vector_free(&data.alcu.board);
	free(data.alcu.need_win);
	return (0);
}
