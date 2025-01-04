/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_set3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:44:38 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/04 11:44:39 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->a.len - ++i)
		ft_swap(&(stacks->a.list[stacks->a.len - i]),
			&(stacks->a.list[stacks->a.len - i - 1]));
	if (stacks->a.len < 2)
		return ;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->b.len - ++i)
		ft_swap(&(stacks->b.list[stacks->b.len - i]),
			&(stacks->b.list[stacks->b.len - i - 1]));
	if (stacks->b.len < 2)
		return ;
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->a.len - ++i)
		ft_swap(&(stacks->a.list[stacks->a.len - i]),
			&(stacks->a.list[stacks->a.len - i - 1]));
	i = 0;
	while (stacks->b.len - ++i)
		ft_swap(&(stacks->b.list[stacks->b.len - i]),
			&(stacks->b.list[stacks->b.len - i - 1]));
	if (stacks->a.len < 2 && stacks->b.len < 2)
		return ;
	ft_printf("rrr\n");
}
