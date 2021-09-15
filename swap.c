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

int	swap_s(t_st *s)
{
	size_t tmp;
	if (s->len > 1)
	{
		tmp = s->stack[0];
		s->stack[0] = s->stack[1];
		s->stack[1] = tmp;
	}
	return 0;
}

int	swap_pa(t_st *a, t_st *b)
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
	return 0;
}


int	swap_reverse_rotate(t_st *s)
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

int	swap_rotate(t_st *s)
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


int	swap_pb(t_st *b, t_st *a)
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
	return 0;
}