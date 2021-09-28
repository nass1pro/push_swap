/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:57:39 by nahaddac          #+#    #+#             */
/*   Updated: 2021/08/07 15:08:45 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	            ft_swap_s_ab(t_st *a, t_st *b)
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
	size_t tmp;
	if (s->len > 1)
	{
		tmp = s->stack[0];
		s->stack[0] = s->stack[1];
		s->stack[1] = tmp;
		return (0);
	}
	return (1);
}

int ft_swap_sa(t_st *a)
{
	if (ft_swap_s(a))
		return (1);
	write(1, "sa\n", 3);
	return (0);
}

int ft_swap_sb(t_st *a)
{
	if (ft_swap_s(a))
		return (1);
	write(1, "sb\n", 3);
	return (0);
}

int	ft_swap_pa(t_st *a, t_st *b)
{
	size_t i = 1;
	int tmp = 0;

	if (b->len == 0)
	{
		return 1;
	}
	else
	{
		i = a->len;
		while(i > 0)
		{
			tmp = a->stack[i];
			a->stack[i] = a->stack[i - 1];
			a->stack[i - 1] = tmp;
			i--;
		}
		a->stack[0] = b->stack[0];
		i = 0;
		while (i < b->len)
		{
			tmp = b->stack[i];
			b->stack[i] = b->stack[i+1];
			b->stack[i+1] = tmp;
			i++;
		}
		b->first = b->stack[0];
		a->first = a->stack[0];
		b->len--;
		a->len++;
		i = b->len;
		while(i++ <= b->len_max)
			b->stack[i] = 0;
	}
	write(1, "pa\n", 3);
	return 0;
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
	return 0;
}

int	            ft_swap_reverse_rotate_b(t_st *s)
{
	if (ft_swap_reverse_rotate(s))
		return (1);
	write(1, "rrb\n", 4);
	return (0);
}

int	            ft_swap_reverse_rotate_a(t_st *s)
{
	if (ft_swap_reverse_rotate(s))
		return (1);
	write(1, "rra\n", 4);
	return (0);
}
int	            ft_swap_reverse_rotate_ab(t_st *a, t_st *b)
{
	if (ft_swap_reverse_rotate(a))
		return (1);
	if (ft_swap_reverse_rotate(b))
		return (1);
	write(1, "rrr\n", 4);
	return 0;
}

int	ft_swap_rotate(t_st *s)
{
	size_t i;

	i = 0;

	s->first = s->stack[1];
	s->end = s->stack[0];
	while (i < s->len)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[i - 1] = s->end;
	return 0;
}

int	            ft_swap_rotate_b(t_st *s)
{
	if (ft_swap_rotate(s))
		return 1;
	write(1, "rb\n", 3);
	return (0);
}

int	            ft_swap_rotate_a(t_st *s)
{
	if (ft_swap_rotate(s))
		return 1;
	write(1, "ra\n", 3);
	return (0);
}

int	            ft_swap_rotate_ab(t_st *a, t_st *b)
{
	if (ft_swap_rotate_a(a))
		return (1);
	if (ft_swap_rotate_b(b))
		return (1);
	write(1, "rr\n", 3);
	return (0);
}

int	ft_swap_pb(t_st *b, t_st *a)
{
	size_t i = 1;
	int tmp = 0;

	if (a->len == 0)
	{
		return 1;
	}
	else
	{
		i = b->len;
		while(i > 0)
		{
			tmp = b->stack[i];
			b->stack[i] = b->stack[i - 1];
			b->stack[i - 1] = tmp;
			i--;
		}
		i = 0;
		b->stack[0] = a->stack[0];
		while (i < a->len)
		{
			tmp = a->stack[i];
			a->stack[i] = a->stack[i+1];
			a->stack[i+1] = tmp;
			i++;
		}
		b->stack[0] = a->first;
		a->first = a->stack[0];
		b->first = b->stack[0];
		a->len--;
		b->len++;
		i = a->len;
		while(i++ <= a->len_max)
			a->stack[i] = 0;
	}
	write(1, "pb\n", 3);
	return 0;
}