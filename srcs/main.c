/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:35 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 12:35:06 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"
#include "../includes/alcu.h"
#include <stdio.h>

int	main(void)
{
	t_vector tab;

	tab.len = 0;
	parsing(&tab);
	printf("%zu\n", tab.len);
	return (0);
}