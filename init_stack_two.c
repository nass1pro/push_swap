/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:06:46 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 19:08:11 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_stack(t_st *a)
{
	free(a->stack);
	if (a->stack_sorted)
		free(a->stack_sorted);
	free(a);
}

t_st	*ft_init_sort_stack(t_st *s)
{
	size_t	i;

	i = -1;
	s->stack_sorted = malloc(sizeof(int) * s->len_max);
	if (!s->stack_sorted)
		return (NULL);
	while (++i < s->len_max)
		s->stack_sorted[i] = s->stack[i];
	return (s);
}

t_st	*ft_init_index_stack(t_st *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s->index = malloc(sizeof(int) * s->len_max);
	if (!s->index)
		return (NULL);
	while (i < s->len_max)
	{
		while (s->stack[j] != s->stack_sorted[i])
			j++;
		s->index[j] = i;
		j = 0;
		i++;
	}
	i = -1;
	while (++i <= s->len_max - 1)
		s->stack[i] = s->index[i];
	free(s->index);
	return (s);
}

t_st	*ft_init_arg(t_st *stack_a, size_t len)
{
	stack_a->first = stack_a->stack[0];
	stack_a->end = len;
	stack_a->len = len;
	stack_a->len_max = len;
	stack_a->error = 0;
	stack_a->index = NULL;
	stack_a->stack_sorted = NULL;
	return (stack_a);
}

t_st	*ft_init_arg_ac(t_st *stack_a, int ac, int i)
{
	stack_a->first = stack_a->stack[0];
	stack_a->end = stack_a->stack[i - 1];
	stack_a->len = ac - 1;
	stack_a->len_max = ac - 1;
	stack_a->stack_sorted = NULL;
	stack_a->index = NULL;
	return (stack_a);
}
