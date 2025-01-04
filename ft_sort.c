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
	while (max >> len)
		len++;
	return (len);
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

static void	brute_force(t_stacks *stacks, int size)
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
		brute_force(stacks, 3);
		pa(stacks);
		pa(stacks);
		return ;
	}
	return (ft_sort_three(stacks));
}

void	ft_sort(t_stacks *stacks)
{
	t_ints	i;

	if (is_sorted(stacks))
		return ;
	if (stacks->a.len == 2 || stacks->a.len == 3 || stacks->a.len == 5)
		return (brute_force(stacks, stacks->a.len));
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
			else if (i.j <= stacks->a.len / 2)
				ra(stacks);
			else
				rra(stacks);
		}
		while (stacks->b.len > 0)
			pa(stacks);
	}
}
