/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:35 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 14:37:01 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include "../includes/alcu.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_vector s_tab;

	if (parsing(&s_tab, ac, av) == 0)
		return (-1);
	return (0);
}