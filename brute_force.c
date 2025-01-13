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

static int	is_sorted(t_stacks *stacks)
{
	int		i;
	long	prev_number;

	if (stacks->b.len != 0)
		return (0);
	prev_number = INT_MIN;
	i = -1;
	while (++i < stacks->a.len)
	{
		if (stacks->a.list[i] < prev_number)
			return (0);
		prev_number = stacks->a.list[i];
	}
	return (1);
}

static int	is_sup_b(t_stacks *stacks)
{
	return (stacks->b.list[0] == 4
		|| (stacks->b.len > 1 && stacks->b.list[0] == 3 && stacks->b.list[1] == 4));
}

void	ft_brute_force(t_stacks *stacks, int size)
{
	if (size == 2)
		return (ra(stacks));
	else if (size == 5)
	{
		pb(stacks);
		pb(stacks);
		ft_brute_force(stacks, 3);
		while (stacks->b.len)
		{
			while (!is_sup_b(stacks) && stacks->a.list[0] < stacks->b.list[0])
				ra(stacks);
			pa(stacks);
			if (stacks->a.list[0] > stacks->a.list[1])
				ra(stacks);
		}
		while (!is_sorted(stacks))
			ra(stacks);
		return ;
	}
	return (sort_three(stacks));
}
