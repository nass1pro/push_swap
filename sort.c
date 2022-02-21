/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:59:19 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 23:01:14 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int search_min(t_st *a)
{
	int i;
	int min;
	// int j;

	min = 2147483647;
	i = 0;
	while(i < (int)a->len)
	{
		if (min > a->stack[i])
			min = a->stack[i];
		i++;
	}
	while (i)
	{
		if (min == a->stack[i])
			return (i);
		i--;
	}
	return 0;
}

void	ft_len_three(t_st *a)
{
	if (a->stack[0] > a->stack[1] && a->stack[1]
		< a->stack[2] && a->stack[0] < a->stack[2])
		ft_swap_sa(a);
	else if (a->stack[0] > a->stack[1] && a->stack[1] > a->stack[2])
	{
		ft_swap_sa(a);
		ft_swap_reverse_rotate_a(a);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2])
		ft_swap_rotate_a(a);
	else if (a->stack[0] < a->stack[1] && a->stack[1]
		> a->stack[2] && a->stack[0] < a->stack[2])
	{
		ft_swap_sa(a);
		ft_swap_rotate_a(a);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2])
	{
		ft_swap_reverse_rotate_a(a);
		ft_swap_sa(a);
	}
	else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2])
		ft_swap_reverse_rotate_a(a);
}

static void ft_sort_short_len(t_st *a, t_st *b)
{
	int i = 0;
	
	i = search_min(a);
	if (i > 0)
		while(i--)
		{
			ft_swap_rotate_a(a);
		}
	ft_swap_pb(b, a);
}

void	len_five(t_st *a, t_st *b)
{
	int	len;

	len = a->len;
	if (len == 4)
	{
		ft_sort_short_len(a, b);
		ft_len_three(a);
		ft_swap_pa(a, b);
	}
	if (len == 5)
	{
		ft_sort_short_len(a, b);
		ft_sort_short_len(a, b);
		ft_len_three(a);
		ft_swap_pa(a, b);
		ft_swap_pa(a, b);
	}
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
}
