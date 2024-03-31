/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:35 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 16:15:37 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "alcu.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_alcu	alcu;

	if (parsing(&alcu.board, ac, av) == -1)
		return (-1);
	if (init_need_win(&alcu) == -1)
		return (-1);
	routine(&alcu);
	vector_free(&alcu.board);
	free(alcu.need_win);
	close(alcu.board.fd);
	return (0);
}
