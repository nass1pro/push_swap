/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:45 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 18:08:50 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


static void ft_init_first(t_st *a, t_st *b)
{
    int i;

    b->first = b->stack[0];
    a->first = a->stack[0];
    a->end = a->stack[a->len];
    b->end = b->stack[b->len - 1];
    b->len--;
    a->len++;
    i = b->len;
	while (i < b->len_max)
		b->stack[i++] = 0;
}

static void ft_swapped_neg(t_st *a)
{
    int tmp;

    tmp = a->stack[i];
	a->stack[i] = a->stack[i - 1];
	a->stack[i - 1] = tmp;
}

static void ft_swapped_pos(t_st *b)
{
    int tmp;

    tmp = b->stack[i];
	b->stack[i] = b->stack[i + 1];
	b->stack[i + 1] = tmp;
}

int	ft_swap_pa(t_st *a, t_st *b)
{
	size_t	i;

	i = 1;
	if (b->len == 0)
		return (1);
	else
	{
		i = a->len;
		while (i > 0)
		{
			ft_swapped_neg(a);
			i--;
		}
		a->stack[0] = b->stack[0];
		i = 0;
		while (i < b->len - 1 )
		{
			ft_swapped_pos(b)
			i++;
		}
		ft_init_first(a, b);
	}
	write(1, "pa\n", 3);
	return (0);
}

int	ft_swap_pb(t_st *b, t_st *a)
{
	size_t	i;

	i = 1;
	if (a->len == 0)
		return (1);
	else
	{
		i = b->len;
		while (i > 0)
		{
            ft_swapped_neg(b);
			i--;
		}
		i = 0;
		b->stack[0] = a->stack[0];
		while (i < a->len)
		{
            ft_swapped_pos(a);
			i++;
		}
        ft_init_first(b, a)
	}
	write(1, "pb\n", 3);
	return (0);
}
