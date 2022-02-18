/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:59:19 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 23:01:41 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_st	*verif_arg(char *av, t_st *stack)
{
	char	**lst;

	if (ft_verif(av) == -1)
		return (NULL);
	lst = ft_split(av, ' ');
	if (!lst)
		return (NULL);
	stack = ft_init_stack(lst);
	return (stack);
}

t_st	*ft_init_radix_sort(t_st *stack_a, t_st *stack_b)
{
	stack_a = ft_init_sort_stack(stack_a);
	if (!stack_a)
		return (NULL);
	stack_a->stack_sorted = ft_quick_sort(stack_a->stack_sorted, 0,
			stack_a->len_max - 1);
	stack_a = ft_init_index_stack(stack_a);
	ft_radix(stack_a, stack_b);
	if (stack_a->error == 1)
	{
		ft_free_stack(stack_b);
		ft_free_stack(stack_a);
		return (NULL);
	}
	return (stack_a);
}

int	ft_start_short_len(t_st *stack_a)
{
	if (ft_verif_sort(stack_a) == 1)
	{
		free(stack_a->stack);
		free(stack_a);
		return (0);
	}
	if (stack_a->len_max == 2)
	{
		ft_swap_sa(stack_a);
		free(stack_a->stack);
		free(stack_a);
		return (0);
	}
	if (stack_a->len_max == 3)
	{
		ft_len_three(stack_a);
		free(stack_a->stack);
		free(stack_a);
		return (0);
	}
	return (0);
}

int	ft_start(t_st *stack_a)
{
	t_st	*stack_b;

	stack_b = NULL;
	if (check_doublon(stack_a->stack, stack_a->len_max))
			return (1);
	if (stack_a->len_max < 4)
		return (ft_start_short_len(stack_a));
	stack_b = ft_init_stack_b(stack_a);
	if (!stack_b)
	{
		free(stack_a->stack);
		free(stack_a);
		return (1);
	}
	else if (stack_a->len_max <= 5)
		len_five(stack_a, stack_b);
	else
	{
		if (!ft_init_radix_sort(stack_a, stack_b))
			ft_write_error(stack_a);
		ft_free_stack_end(stack_a, stack_b);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_st	*stack_a;
	char	**lst;

	lst = NULL;
	stack_a = NULL;
	if (ac < 2)
		return (-1);
	if (ac == 2)
	{
		stack_a = verif_arg(av[1], stack_a);
		if (!stack_a)
			return (ft_write_error(NULL));
	}
	else
	{
		if (ft_multi_arg_verif(ac, av) == -1)
			return (write(1, "Error\n", 6));
		stack_a = ft_init_stack_list(av, ac);
		if (!stack_a)
			return (-1);
	}
	if (ft_start(stack_a))
		return (ft_write_error(stack_a));
	return (0);
}
