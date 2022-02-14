/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:59:19 by nahaddac          #+#    #+#             */
/*   Updated: 2021/08/07 15:34:39 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_radix(t_st *a, t_st *b)
{
	int	i;
	int	j;
	int max_num = a->len_max - 1;
	int max_bits = 0;

	i = -1;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < (int)a->len_max)
		{
			if (((a->stack[0] >> i) & 1) == 1)
			{
				ft_swap_rotate_a(a);
			}
			else
			{
				ft_swap_pb(b, a);
			}
		}
		while (b->len != 0)
			ft_swap_pa(a, b);
	}
	return (0);
}
