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

static int	get_bit_len(t_stacks *stacks)
{
	int		i;
	int		len;
	long	max;

	max = INT_MIN;
	i = -1;
	while (++i < stacks->a.len)
		if (stacks->a.list[i] > max)
			max = stacks->a.list[i];
	len = 0;
	while (max >> ++len)
		;
	return (len);
}

static void	ft_sort_b(t_stacks *stacks, int bit_len, int step)
{
	t_ints	i;

	i.i = -1;
	while (++(i.i) < bit_len)
	{
		i.j = -1;
		i.len = stacks->b.len;
		while (++(i.j) < i.len)
		{
			if (((stacks->b.list[0] >> i.i) & 1) == 0)
				pa(stacks);
			else if (i.i == step && stacks->a.len > i.j)
				rr(stacks);
			else
				rb(stacks);
		}
	}
}

void	ft_sort(t_stacks *stacks)
{
	t_ints	i;

	if (is_sorted(stacks))
		return ;
	if (stacks->a.len == 2 || stacks->a.len == 3 || stacks->a.len == 5)
		return (ft_brute_force(stacks, stacks->a.len));
	i.width = get_bit_len(stacks);
	i.i = -1;
	while (++(i.i) < i.width)
	{
		i.j = -1;
		i.len = stacks->a.len;
		while (++(i.j) < i.len)
		{
			if (((stacks->a.list[0] >> i.i) & 1) == 0)
				pb(stacks);
			else
				ra(stacks);
		}
		ft_sort_b(stacks, i.width, i.i);
	}
}
