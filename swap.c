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

void	*swap_s(t_st *s)
{
	int tmp;
	if (s->len > 1)
	{
		tmp = s->stack[0];
		s->stack[0] = s->stack[1];
		s->stack[1] = tmp;
	}
	return ;
}

void	*swap_pa(t_st *a, t_st *b)
{
	int	i;

	if (b->len == 0)
		return ;
	b->len--;
	a->first = b->first;
	a->len++;
	i = a->len;
	while (i > 0)
	{
		a->stack[i + 1] = a->stack[i];
		i--;
	}
	i = b->len;
	while (i > 0)
	{
		b->stack[i + 1] = b->stack [i];
		i--;
	}
	b->first = b->stack[0];
	a->stack[0] = a->first;
}


void	*swap_reverse_rotate(t_st *s)
{
	int	i;

	i = s->len;
	s->first = s->stack[len];
	while (i > 0)
	{
		s->stack[i + 1] = s->stack[i];
		i--;
	}
	s->stack[0] = s->stack[first];
}

void	*swap_rotate(t_st *s)
{
	int i;

	i = 0;

	s->first = s->stack[1];
	s->end = s->stack[0];
	while (i < s->len)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[0] = s->end;
}
