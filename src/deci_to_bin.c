/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deci_to_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelmeni <eljok87@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:41:15 by mdelmeni          #+#    #+#             */
/*   Updated: 2024/08/12 10:41:15 by mdelmeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deci_to_bin.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_atoi(char *str)
{
	int result;
	int signe;

	result = 0;
	signe = 0;
	while (*str == 32 || (*str >= 7 && *str <= 13) || *str == '-' || *str == '+')
	{
		if (*str == '-')
			signe += 1;
		str++;
	}
	if ( signe %2 != 0)
		signe = -1;
	else
		signe = 1;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return( result * signe);
}

void	deci_to_bin(int deci)
{
	int i;
	char bin[33];

	i = 31;
	bin[32] = '\0';
	if (deci == 0)
	{
		bin[i] = '0';
		i--;
	}
	while (deci > 0)
	{
		bin[i] = (deci % 2) + '0';
		deci = deci / 2;
		i--;
	}
	while (i >= 0)
	{
		bin[i] = '0';
		i--;
	}
	ft_putstr(bin);
}
