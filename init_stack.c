/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:59:19 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/19 19:57:10 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_st	*ft_init_stack_list(char **a, int ac)
{
	int		i;
	t_st	*stack_a;
	long	max;
	int 	j;

	i = 1;
	stack_a = NULL;
	stack_a = ft_alloc_stack(stack_a, ac);
	max = 0;
	j = 0;
	if (!stack_a)
		return (NULL);
	while (i <= ac - 1)
	{
		max = ft_atoi(a[i]);
		stack_a->stack[i - 1] = (int)max;
		if (max > 2147483647 || max < -2147483648)
		{
			return (NULL);
		}
		i++;
	}
	stack_a->first = stack_a->stack[0];
	stack_a->end = stack_a->stack[i - 1];
	stack_a->len = ac - 1;
	stack_a->len_max = ac - 1;
	stack_a->stack_sorted = NULL;
	stack_a->index = NULL;
	return (stack_a);
}

t_st	*ft_init_stack(char **lst)
{
	size_t	i;
	size_t	len;
	t_st	*stack_a;

	i = 0;
	len = 0;
	stack_a = NULL;
	
	while (lst[len] != NULL)
		len++;
	stack_a = ft_alloc_stack(stack_a, len + 1);
	if (!stack_a)
		return (NULL);
	i = 0;
	while (i < len)
	{
		stack_a->stack[i] = ft_atoi(lst[i]);
		if (stack_a->stack[i] > 2147483647 || stack_a->stack[i] < -2147483648)
			return (NULL);
		i++;
	}
	stack_a->first = stack_a->stack[0];
	stack_a->end = len;
	stack_a->len = len;
	stack_a->len_max = len;
	stack_a->error = 0;
	// stack_a->index = NULL;
	return (stack_a);
}

t_st	*ft_init_stack_b(t_st *a)
{
	t_st	*stack_b;

	stack_b = NULL;
	stack_b = ft_alloc_stack(stack_b, a->len_max);
	if (!stack_b)
		return (NULL);
	stack_b->len = 0;
	stack_b->len_max = a->len_max;
	return (stack_b);
}

t_st	*ft_alloc_stack(t_st *st, int len_max)
{
	st = malloc(sizeof(t_st));
	if (st)
	{
		st->stack = malloc(sizeof(int) * len_max);
		if (!st->stack)
		{
			free(st);
			return (NULL);
		}
	}
	else
		return (NULL);
	return (st);
}
