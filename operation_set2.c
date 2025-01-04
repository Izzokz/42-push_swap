/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_set2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:38:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/04 11:38:27 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->a.len - 1)
		ft_swap(&(stacks->a.list[i]), &(stacks->a.list[i + 1]));
	if (i == 0)
		return ;
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->b.len - 1)
		ft_swap(&(stacks->b.list[i]), &(stacks->b.list[i + 1]));
	if (i == 0)
		return ;
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->a.len - 1)
		ft_swap(&(stacks->a.list[i]), &(stacks->a.list[i + 1]));
	i = -1;
	while (++i < stacks->b.len - 1)
		ft_swap(&(stacks->b.list[i]), &(stacks->b.list[i + 1]));
	if (stacks->a.len < 2 && stacks->b.len < 2)
		return ;
	ft_printf("rr\n");
}
