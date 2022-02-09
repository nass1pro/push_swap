/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:59:19 by nahaddac          #+#    #+#             */
/*   Updated: 2021/08/07 15:34:39 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_multi_arg_verif(int ac, char *av)
{
	int i;

	i = 1;
	while (i <= (size_t)ac - 1)
	{
			if (ft_verif(av[i]) == -1)
				return (-1);
			i++;
	}
}

static int ft_write_error(t_st stack)
{
	write(1, "Error\n", 6);
	if (stack)
		ft_free_stack(stack)
	return (-1);
}

static t_st verif_arg(char *av, t_st *stack)
{
	char	**lst;

	if (ft_verif(av[1]) == -1)
			return (NULL);
	lst = ft_split(av[1], ' ');
	if (!lst)
		return NULL;
	stack_a = ft_init_stack(lst)
	return (stack_a);
}

int ft_start(t_st *stack_a)
{
	t_st *stack_b;

	stack_b = NULL;
	if (ft_verif_sort(stack_a) == -1)
	{
		write(1, "OK\n", 3);
		ft_free_stack(stack_a);
		return (0);
	}
	stack_b = ft_init_stack_b(stack_a);
	if (!stack_b)
		return (1);
	// len_five(stack_a, stack_b);
	stack_a = ft_init_sort_stack(stack_a);
	if (!stack_a)
		return 1;
	stack_a->stack_sorted = ft_quick_sort(stack_a->stack_sorted, 0, stack_a->len_max - 1);
	stack_a = ft_init_index_stack(stack_a);
	if (stack_a->error == 1)
	{
		ft_free_stack(stack_b);
		ft_free_stack(stack_a);
		return (1);
	}
}

int main(int ac, char **av)
{
	t_st	*stack_a;
	size_t	i;
	
	lst = NULL;
	stack_a = NULL;
	i = 1;
	if (ac < 2)
		return(-1);
	if (ac == 2)
	{
		stack_a = verif_arg(av[1], stack_a);
		if (!stack_a)
			return (ft_write_error(NULL));
	}
	else
	{
		ft_multi_arg_verif(ac, av[1]);
		stack_a = ft_init_stack_list(av, ac);
		if (!stack_a)
			return -1;
	}
	if (ft_start(t_st *stack_a))
		return ft_write_error(stack_a);
	return (0);
	
	
	// if (stack_a->len == 3)
	// 	ft_len_three(stack_a);
	// else
	// 	len_five(stack_a, stack_b);
	// // visual_stack(stack_a,stack_b);
	// if (ft_verif_sort(stack_a) == -1)
	// {
	// 	printf("OK");
	// }
	// size_t id = -1;
	// while( ++id  < stack_a->len_max)
	// {
	// 	printf("%zu index %d = ",id ,stack_a->index[id]);
	// 	printf(" value %d \n",stack_a->stack_sorted[id]);
	// }
	// visual_stack(stack_a, stack_b);
	// ft_free_stack(stack_b);
	// ft_free_stack(stack_a);
	return(0);
}
