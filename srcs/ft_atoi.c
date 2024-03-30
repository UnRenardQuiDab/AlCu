/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:40:52 by fsariogl          #+#    #+#             */
/*   Updated: 2024/03/30 12:41:00 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_minmax(long long nb, int signe)
{
	if (nb > 9223372036854775807 && signe == 1)
		return (-1);
	if (nb < -9223372036854775807 || nb > 9223372036854775807)
	{
		if (signe == 1)
			return (-1);
		return (0);
	}
	return ((int)nb * signe);
}

int	ft_atoi(const char *str)
{
	int			i;
	char		*s;
	long long	nb;
	int			signe;

	i = 0;
	signe = 1;
	s = (char *)str;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-')
		signe = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	nb = 0;
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		nb = ((nb * 10) + s[i]) - '0';
		i++;
	}
	return (ft_check_minmax(nb, signe));
}