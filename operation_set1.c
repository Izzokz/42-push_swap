/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_set1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:30:11 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/04 11:30:13 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	if (stacks->a.len >= 2)
	{
		ft_printf("sa\n");
		ft_swap(&(stacks->a.list[0]), &(stacks->a.list[1]));
	}
}

void	sb(t_stacks *stacks)
{
	if (stacks->b.len >= 2)
	{
		ft_printf("sb\n");
		ft_swap(&(stacks->b.list[0]), &(stacks->b.list[1]));
	}
}

void	ss(t_stacks *stacks)
{
	if (stacks->a.len >= 2)
		ft_swap(&(stacks->a.list[0]), &(stacks->a.list[1]));
	if (stacks->b.len >= 2)
		ft_swap(&(stacks->b.list[0]), &(stacks->b.list[1]));
	if (stacks->a.len < 2 && stacks->b.len < 2)
		return ;
	ft_printf("ss\n");
}

void	pa(t_stacks *stacks)
{
	if (stacks->b.len > 0)
	{
		ft_realloc_list(&(stacks->a));
		if (!(stacks->a.list))
		{
			ft_printf_err("Error (pa):ft_realloc_list()", 1);
			ft_exit(stacks);
		}
		stacks->a.list[0] = stacks->b.list[0];
		ft_dealloc_list(&(stacks->b));
		if (!(stacks->b.list))
		{
			ft_printf_err("Error (pa):ft_dealloc_list()", 1);
			ft_exit(stacks);
		}
		ft_printf("pa\n");
	}
}

void	pb(t_stacks *stacks)
{
	if (stacks->a.len > 0)
	{
		ft_realloc_list(&(stacks->b));
		if (!(stacks->b.list))
		{
			ft_printf_err("Error (pb):ft_realloc_list()", 1);
			ft_exit(stacks);
		}
		stacks->b.list[0] = stacks->a.list[0];
		ft_dealloc_list(&(stacks->a));
		if (!(stacks->a.list))
		{
			ft_printf_err("Error (pb):ft_dealloc_list()", 1);
			ft_exit(stacks);
		}
		ft_printf("pb\n");
	}
}
