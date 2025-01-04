/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:33:19 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/04 16:33:20 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	int		i;
	long	prev_number;

	if (stacks->b.len != 0)
		return (0);
	prev_number = LONG_MIN;
	i = -1;
	while (++i < stacks->a.len)
	{
		if (stacks->a.list[i] < prev_number)
			return (0);
		prev_number = stacks->a.list[i];
	}
	return (1);
}

void	ft_sort(t_stacks *stacks)
{
	ft_printf("Sort: %_1\n", is_sorted(stacks));
}
