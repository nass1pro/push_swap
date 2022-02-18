/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:37:57 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 18:38:15 by nahaddac         ###   ########.fr       */
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