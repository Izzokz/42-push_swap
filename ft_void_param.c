/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:45:52 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/07 10:45:53 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_void_param(const char *param, t_stacks *stacks)
{
	int	i;
	int	spaces;

	i = -1;
	spaces = 0;
	while (param[++i])
		if (param[i] == ' ')
			spaces++;
	if (!i || spaces == i)
	{
		ft_printf_fd("Error\n", 2);
		ft_exit(stacks);
	}
}
