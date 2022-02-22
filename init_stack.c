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

t_st	*ft_init_stack_list(char **a, int ac, t_st *stack_a)
{
	int		i;
	long	max;

	i = 1;
	stack_a = ft_alloc_stack(stack_a, ac);
	max = 0;
	if (!stack_a)
		return (NULL);
	while (i <= ac - 1)
	{
		max = ft_atoi(a[i]);
		stack_a->stack[i - 1] = (int)max;
		if (max > 2147483647 || max < -2147483648)
		{
			free(stack_a->stack);
			free(stack_a);
			return (NULL);
		}
		i++;
	}
	stack_a = ft_init_arg_ac(stack_a, ac, i);
	return (stack_a);
}

t_st	*ft_init_stack(char **lst, t_st *stack_a)
{
	size_t	i;
	size_t	len;
	long	max;

	len = 0;
	while (lst[len] != NULL)
		len++;
	stack_a = ft_alloc_stack(stack_a, len + 1);
	if (!stack_a)
		return (NULL);
	i = 0;
	while (i < len)
	{
		max = ft_atoi(lst[i]);
		stack_a->stack[i] = max;
		if (max > 2147483647 || max < -2147483648)
		{
			free(stack_a->stack);
			free(stack_a);
			return (NULL);
		}
		i++;
	}
	stack_a = ft_init_arg(stack_a, len);
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
