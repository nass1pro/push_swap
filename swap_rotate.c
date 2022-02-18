/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:35:34 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 18:40:41 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_swap_rotate(t_st *s)
{
	size_t	i;

	i = -1;
	s->first = s->stack[1];
	s->end = s->stack[0];
	while (++i < s->len)
	{
		s->stack[i] = s->stack[i + 1];
	}
	s->stack[i - 1] = s->end;
	return (0);
}

int	ft_swap_rotate_b(t_st *s)
{
	ft_swap_rotate(s);
	write(1, "rb\n", 3);
	return (0);
}

int	ft_swap_rotate_a(t_st *s)
{
	ft_swap_rotate(s);
	write(1, "ra\n", 3);
	return (0);
}

int	ft_swap_rotate_ab(t_st *a, t_st *b)
{
	if (ft_swap_rotate_a(a))
		return (1);
	if (ft_swap_rotate_b(b))
		return (1);
	write(1, "rr\n", 3);
	return (0);
}