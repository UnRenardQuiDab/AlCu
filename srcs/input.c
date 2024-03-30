/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:39:43 by bwisniew          #+#    #+#             */
/*   Updated: 2024/03/30 17:38:40 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdlib.h>

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n > 9 || n < -9)
	{
		if (n < 0)
			ft_putnbr_fd(-(n / 10), fd);
		else
			ft_putnbr_fd(n / 10, fd);
	}
	if (n < 0)
		ft_putchar_fd(-(n % 10) + 48, fd);
	else
		ft_putchar_fd((n % 10) + 48, fd);
}

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
