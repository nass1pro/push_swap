/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:47:10 by mkravetz          #+#    #+#             */
/*   Updated: 2021/11/08 17:31:27 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_max_bits(int *ind, t_st *stack)
{
	int	max_nb;
	int	res;

	res = 0;
	fprintf(stderr,"len == %zu\n", stack->len);
	max_nb = ind[stack->len];
	while (max_nb)
	{
		max_nb = max_nb >> 1;
		++res;
	}
	return (res);
}

void	ft_radixsort(int *ind, t_st *b, t_st *a)
{
	int i = 0;
	size_t j = 0;
	size_t len_b;

	while(i < ft_get_max_bits(ind, a))
	{
		len_b = 0;
		while(j < a->len)
		{
			if (((ind[j] >> i) & 1) == 0)
			{
				ft_swap_pb(b, a); // a doit etre ind (et du coup changer pb)
				len_b++;
			}
			else
				ft_swap_rotate_a(a);
			j++;
		}
		while(len_b > 0)
		{
			ft_swap_pa(a, b);
			len_b--;
		}
		i++;
	}
}
