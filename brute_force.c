/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:26:31 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 11:50:42 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *stacks)
{
	if (stacks->a.list[0] < stacks->a.list[1]
		&& stacks->a.list[1] < stacks->a.list[2])
		return ;
	if (stacks->a.list[0] > stacks->a.list[1]
		&& stacks->a.list[1] > stacks->a.list[2])
	{
		sa(stacks);
		rra(stacks);
	}
	else if (stacks->a.list[0] > stacks->a.list[1]
		&& stacks->a.list[0] < stacks->a.list[2])
		sa(stacks);
	else if (stacks->a.list[0] < stacks->a.list[1]
		&& stacks->a.list[0] > stacks->a.list[2])
		rra(stacks);
	else if (stacks->a.list[0] < stacks->a.list[1]
		&& stacks->a.list[1] > stacks->a.list[2])
	{
		sa(stacks);
		ra(stacks);
	}
	else
		ra(stacks);
}

static int	find_min_index(t_stacks *stacks)
{
	int	min;
	int	min_index;
	int	i;

	min = stacks->a.list[0];
	min_index = 0;
	i = -1;
	while (++i < stacks->a.len)
	{
		if (stacks->a.list[i] < min)
		{
			min = stacks->a.list[i];
			min_index = i;
		}
	}
	return (min_index);
}

void	ft_brute_force(t_stacks *stacks, int size)
{
	int	min_index;

	if (size == 2)
		return (ra(stacks));
	else if (size == 5)
	{
		min_index = find_min_index(stacks);
		while (min_index-- > 0)
			ra(stacks);
		pb(stacks);
		min_index = find_min_index(stacks);
		while (min_index-- > 0)
			ra(stacks);
		pb(stacks);
		ft_brute_force(stacks, 3);
		pa(stacks);
		pa(stacks);
		return ;
	}
	return (sort_three(stacks));
}
