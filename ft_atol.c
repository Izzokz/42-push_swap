/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:57:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/04 15:57:59 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	number;
	int		index;
	int		sign;

	number = 0;
	index = 0;
	sign = 1;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index])
	{
		if (ft_isdigit(str[index]))
			number = number * 10 + str[index] - 48;
		else
			break ;
		index++;
	}
	return (number * sign);
}
