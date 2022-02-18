/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:57:39 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 18:38:25 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_swap_reverse_rotate(t_st *s)
{
	size_t	i;

	i = s->len;
	s->first = s->stack[s->len - 1];
	while (i > 0)
	{
		s->stack[i] = s->stack[i - 1];
		i--;
	}
	s->stack[0] = s->first;
	s->end = s->stack[s->len - 1];
	return (0);
}

int	ft_swap_reverse_rotate_b(t_st *s)
{
	if (ft_swap_reverse_rotate(s))
		return (1);
	write(1, "rrb\n", 4);
	return (0);
}

int	ft_swap_reverse_rotate_a(t_st *s)
{
	if (ft_swap_reverse_rotate(s))
		return (1);
	write(1, "rra\n", 4);
	return (0);
}

int	ft_swap_reverse_rotate_ab(t_st *a, t_st *b)
{
	if (ft_swap_reverse_rotate(a))
		return (1);
	if (ft_swap_reverse_rotate(b))
		return (1);
	write(1, "rrr\n", 4);
	return (0);
}
