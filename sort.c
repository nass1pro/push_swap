/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:59:19 by nahaddac          #+#    #+#             */
/*   Updated: 2021/08/07 15:34:39 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	{
		ft_swap_reverse_rotate_a(a);
	}
}

static void	ft_five(t_st *a, t_st *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	// if (b->stack[0] < b->stack[1] && b->len != 1)
	// 	return ;
	while (b->stack[0] > a->stack[i] && i != a->len)
		i++;
	// printf("len = %zu i = %zu\n",a->len, i);
	if (i == 0)
		ft_swap_pa(a, b);
	
	else if (i == a->len)
	{
		ft_swap_pa(a, b);
		ft_swap_rotate_a(a);
		return ;
	}
	else
	{
		j = i;
		while (j--)
			ft_swap_rotate_a(a);
		ft_swap_pa(a, b);
		while (i-- >= 1)
			ft_swap_reverse_rotate_a(a);
	}
}

void	len_five(t_st *a, t_st *b)
{
	int	len;

	len = a->len;
	if (a->len > 4)
		ft_swap_pb(b, a);
	ft_swap_pb(b, a);
	if (b->stack[0] > b->stack[1])
		ft_swap_sb(b);
	ft_len_three(a);
	ft_five(a, b);
	if (len == 5)
		ft_five(a, b);
}
