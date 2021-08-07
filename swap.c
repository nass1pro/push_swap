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

t_st *swap_s(t_st *s)
{
    int tmp;
    if (s->len > 1)
    {
        tmp = s->stack[0];
        s->stack[0] = s->stack[1];
        s->stack[1] = tmp;
    }
    return (s);
}

t_st *swap_pa(t_st *a, t_st *b)
{
    int tmp;
    if (!b->stack)

    tmp = b->stack[1];
    a-stack
}
