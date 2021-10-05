/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:43 by mkravetz          #+#    #+#             */
/*   Updated: 2021/10/05 17:25:59 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_len_three(t_st *a)
{
	if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2] && a->stack[0] < a->stack[2])
		ft_swap_sa(a);
	else if (a->stack[0] > a->stack[1] && a->stack[1] > a->stack[2])
	{
		ft_swap_sa(a);
		ft_swap_reverse_rotate_a(a);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2])
		ft_swap_rotate_a(a);
	else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2] && a->stack[0] < a->stack[2])
	{
		ft_swap_sa(a);
		ft_swap_rotate_a(a);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2])
	{
		ft_swap_reverse_rotate_a(a);
		ft_swap_sa(a);
	}
	else
		ft_swap_reverse_rotate_a(a);
}

static void ft_five(t_st *a, t_st *b)
{
	size_t i;
	size_t j;

	i = 1;
	j = 0;
	if (b->stack[0] < b->stack[1] && b->len != 1)
		return ;
	while(b->stack[0] > a->stack[i] && i != a->len)
		i++;
	if (i == 1)
	{
		// visual_stack(a, b);
		ft_swap_pa(a, b);
	}

	else if (i == a->len)
	{
		// visual_stack(a, b);
		ft_swap_pa(a, b);
		ft_swap_rotate_a(a);
	}
	else
	{
		int j = i;
		while(j--)
			ft_swap_rotate_a(a);
		ft_swap_pa(a, b);
		while(i-- > 1)
			ft_swap_reverse_rotate_a(a);
	}
}

void len_five(t_st *a, t_st *b)
{
	int len =  a->len;

	if (a->len > 4)
		ft_swap_pb(b, a);
	ft_swap_pb(b, a);
	if (b->stack[0] < b->stack[1])
		ft_swap_sb(b);
	ft_len_three(a);
	// visual_stack(a, b);
	ft_five(a, b);
	if (len == 5)
		ft_five(a, b);
	// if ()
}
