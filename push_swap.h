/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:30:16 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/04 11:30:19 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "010_FT_PRINTF/ft_printf.h"
# include "020_LIBFT/libft.h"

typedef struct s_stk
{
	long	*list;
	int		len;
}		t_stk;

typedef struct s_stacks
{
	t_stk	a;
	t_stk	b;
}		t_stacks;

void	ft_void_param(const char *param, t_stacks *stacks);
long	ft_atol(const char *str);
void	ft_swap(long *i, long *j);
void	ft_realloc_list(t_stk *stk);
void	ft_dealloc_list(t_stk *stk);
void	ft_exit(t_stacks *stacks);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
void	ft_brute_force(t_stacks *stacks, int size);
void	ft_sort(t_stacks *stacks);

#endif
