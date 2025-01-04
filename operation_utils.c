/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:01:39 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/04 12:01:40 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(long *i, long *j)
{
	long	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

void	ft_realloc_list(t_stk *stk)
{
	long	*new_list;
	int		i;

	new_list = ft_calloc(stk->len + 1, sizeof(long));
	if (!new_list)
	{
		free(stk->list);
		stk->list = new_list;
		return ;
	}
	stk->len++;
	i = 0;
	while (++i < stk->len)
		new_list[i] = stk->list[i - 1];
	free(stk->list);
	stk->list = new_list;
}

void	ft_dealloc_list(t_stk *stk)
{
	long	*new_list;
	int		i;

	new_list = ft_calloc(stk->len, sizeof(long));
	if (!new_list)
	{
		free(stk->list);
		stk->list = new_list;
		return ;
	}
	stk->len--;
	i = -1;
	while (++i < stk->len)
		new_list[i] = stk->list[i + 1];
	free(stk->list);
	stk->list = new_list;
}

void	ft_exit(t_stacks *stacks)
{
	free(stacks->a.list);
	free(stacks->b.list);
	exit(-1);
}
