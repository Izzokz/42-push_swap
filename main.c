/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:28:48 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/04 14:28:49 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	ft_print_stacks(t_stacks *stacks)
{
	int	i;

	i = -1;
	ft_printf("a:\n");
	while (++i < stacks->a.len)
		ft_printf("\t%i\n", stacks->a.list[i]);
	i = -1;
	ft_printf("b:\n");
	while (++i < stacks->b.len)
		ft_printf("\t%i\n", stacks->b.list[i]);
}
*/

static int	valid_numbers(t_stk a)
{
	t_ints	i;

	i.i = 0;
	while (++(i.i) < a.len)
	{
		if (a.list[i.i] < INT_MIN || a.list[i.i] > INT_MAX)
			return (0);
		i.j = -1;
		while (++(i.j) < a.len)
			if (i.i != i.j && a.list[i.i] == a.list[i.j])
				return (0);
	}
	return (1);
}

static int	numeric_args(char **chain)
{
	t_ints	i;

	i.i = -1;
	while (chain[++(i.i)])
	{
		i.j = -1;
		while (chain[i.i][++(i.j)])
			if (!ft_isdigit(chain[i.i][i.j])
				&& (i.j == 0 && chain[i.i][i.j] != '-'))
				return (0);
	}
	return (1);
}

static void	ft_split_trans_a(t_stacks *stacks, char **split, char **temp)
{
	int	i;

	free(*temp);
	if (!numeric_args(split))
	{
		ft_printf("Error\n");
		ft_free_rlines(&split);
		ft_exit(stacks);
	}
	i = -1;
	stacks->a.len = ft_rlines_len(split);
	stacks->a.list = ft_calloc(stacks->a.len + 1, sizeof(long));
	if (!stacks->a.list)
	{
		ft_printf_err("Internal Error:ft_calloc()", 1);
		ft_free_rlines(&split);
		ft_exit(stacks);
	}
	while (split[++i])
		stacks->a.list[i] = ft_atol(split[i]);
	ft_free_rlines(&split);
}

static void	ft_parse_args(t_stacks *stacks, int argc, char **argv)
{
	int		i;
	char	*temp;

	temp = NULL;
	i = 0;
	while (++i < argc)
	{
		temp = gnlxio_ft_strjoinfree(&temp, &(char *){ft_strdup(" ")});
		if (temp[ft_strlen(temp) - 1] != ' ')
		{
			ft_printf_err("Internal Error:gnlxio_ft_strjoinfree()", 1);
			free(temp);
			ft_exit(stacks);
		}
		temp = gnlxio_ft_strjoinfree(&temp, &(char *){ft_strdup(argv[i])});
	}
	if (!temp)
		return ;
	ft_split_trans_a(stacks, (char **){ft_split(temp, ' ')}, &temp);
	if (!valid_numbers(stacks->a))
	{
		ft_printf("Error\n");
		ft_exit(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_stk		a;
	t_stk		b;
	t_stacks	stacks;

	if (argc < 2)
		return (-1);
	b.len = 0;
	b.list = ft_calloc(1, sizeof(long));
	if (!(b.list))
	{
		ft_printf_err("Internal Error:ft_calloc()", 1);
		return (-1);
	}
	a.list = NULL;
	stacks.a = a;
	stacks.b = b;
	ft_parse_args(&stacks, argc, argv);
	free(stacks.a.list);
	free(stacks.b.list);
}
