/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:39:43 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/31 11:55:15 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdlib.h>

int	valid_input(char *input, int max)
{
	int	num;

	if (!input)
		return (0);
	num = ft_atoi(input);
	if (num >= 1 && num <= 3 && num <= max)
		return (1);
	else
	{
		ft_putnbr_fd(num, 2);
		ft_error(" - Invalid choice\n");
		return (0);
	}
}

int	get_user_input(int max)
{
	char	*input;
	int		value;

	write(1, "Please choose between 1 and 3 items\n", 36);
	while ((input = get_next_line(0)) != NULL)
	{
		if (valid_input(input, max))
		{
			value = ft_atoi(input);
			free(input);
			return (value);
		}
		free(input);
		write(1, "Please choose between 1 and 3 items\n", 36);
	}
	return (-1);
}
