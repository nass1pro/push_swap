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
	size_t i = a->len;

	fprintf(stderr,"%d ---", b->stack[2]);
	if (b->len == 0)
	{
		return 1;
	}
	else
	{
		while(i > 0)
		{
			a->stack[i - 1] = a->stack[i];
			i--;
		}
		a->stack[0] = b->first;
		while (i < b->len)
		{
			b->stack[i] = b->stack[i + 1];
			i++;
		}
		b->len--;
		a->len++;
	}
	return 0;
}


int	swap_reverse_rotate(t_st *s)
{
	size_t	i;

	i = s->len;
	// printf("%d\n", s->len);
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
	// printf("%d\n", s->end);
	s->end = s->stack[0];
	while (i < s->len)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[i - 1] = s->end;
	return 0;
}
