/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelmeni <eljok87@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:08:00 by mdelmeni          #+#    #+#             */
/*   Updated: 2024/08/12 16:08:00 by mdelmeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deci_to_bin.h"

int	main(int ac, char **av)
{
	int deci;
	if (ac == 2)
	{
		deci = ft_atoi(av[1]);
		deci_to_bin(deci);
	}
	write (1, "\n", 1);
	return (0);
}
