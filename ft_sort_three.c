/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:26:31 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/04 19:26:32 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stacks *stacks)
{
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
