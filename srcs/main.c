/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:56:35 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 14:32:33 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "alcu.h"
#include <stdio.h>

int	main(void)
{
	t_vector	tab;

	vector_init(&tab);
	printf("%zu\n", tab.len);
	while (1)
	{
		printf("input : %d\n", get_user_input(2));
	}
	
	return (0);
}
