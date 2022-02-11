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

	i = 0;
	j = 0;
	while (true)
	{
		j = 0;
		while (j < a->len)
		{
			if ((a->first >> i) & 1)
				ft_swap_rotate_a(a);
			else
				ft_swap_pb(b, a);
			j++;
		}
		while (b->len)
			ft_swap_pa(a, b);
		if (ft_verif_sort(a) == -1)
			break ;
		i++;
	}
}
