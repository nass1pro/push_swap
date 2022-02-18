/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:57:39 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 18:31:36 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_swap_s_ab(t_st *a, t_st *b)
{
	if (ft_swap_s(a))
		return (1);
	if (ft_swap_s(b))
		return (1);
	write(1, "ss\n", 3);
	return (0);
}

int	ft_swap_s(t_st *s)
{
	size_t	tmp;

	if (s->len > 1)
	{
		tmp = s->stack[0];
		s->stack[0] = s->stack[1];
		s->stack[1] = tmp;
		return (0);
	}
	return (1);
}

int	ft_swap_sa(t_st *a)
{
	if (ft_swap_s(a))
		return (1);
	write(1, "sa\n", 3);
	return (0);
}

int	ft_swap_sb(t_st *a)
{
	if (ft_swap_s(a))
		return (1);
	write(1, "sb\n", 3);
	return (0);
}

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
