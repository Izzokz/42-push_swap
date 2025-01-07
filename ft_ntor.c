/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:10:39 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/07 15:10:42 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_max(t_stk a, int *i_max, long *max)
{
	int	i;

	i = -1;
	while (++i < a.len)
	{
		if (a.list[i] > *max)
		{
			*i_max = i;
			*max = a.list[i];
		}
	}
}

/*
Number to Rank
Example :
9 13 8 15 -9
    >>>
2 3 1 4 0
*/
void	ft_ntor(t_stacks *stacks)
{
	long	*new_stk;
	long	max;
	int		i_max;
	int		rank;

	max = INT_MIN;
	new_stk = ft_calloc(stacks->a.len + 1, sizeof(long));
	if (!new_stk)
	{
		ft_printf_err("Internal Error:ft_calloc()", 1);
		ft_exit(stacks);
	}
	rank = stacks->a.len;
	while (--rank >= 0)
	{
		get_max(stacks->a, &i_max, &max);
		stacks->a.list[i_max] = (long)INT_MIN - 1;
		new_stk[i_max] = rank;
		max = (long)INT_MIN - 1;
	}
	free(stacks->a.list);
	stacks->a.list = new_stk;
}
