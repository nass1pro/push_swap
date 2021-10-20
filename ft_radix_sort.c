/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:10 by mkravetz          #+#    #+#             */
/*   Updated: 2021/10/20 14:37:03 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_max_bits(t_st *stack)
{
	int	max_nb;
	int	res;

	res = 0;
	max_nb = stack->len_max - 1;
	while (max_nb)
	{
		max_nb = max_nb >> 1;
		++res;
	}
	return (res);
}

void	ft_radixsort(t_st *a, t_st *b)
{
	int	i;
	int	j;
	int	push_back;
	int	max_bits;

	push_back = 0;
	max_bits = ft_get_max_bits(a);
	i = -1;
	while (++i < max_bits)
	{
		j = a->first + 1;
		while (--j >= 0)
		{
			if (((a->stack[a->first] >> i) & 1) == 0)
			{
				ft_swap_pb(b, a);
				++push_back;
			}
			else
				ft_swap_rotate_a(a);
		}
		++push_back;
		while (--push_back)
			ft_swap_pa(a, b);
	}
}
