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

static int ft_verif_sort(t_st *a)
{
	size_t i;
	size_t v;
	//size_t t;

	i = 0;
	v = 1;
	//t = 0;
	while (v < a->len_max)
	{
		if (a->stack[i] >= a->stack[v])
			return 0;
		i++;
		v++;
	}
	return -1;
}

static int ft_verif(char *str)
{
	size_t i;

	i = 0;
	while(i < ft_strlen(str))
	{

		if (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return(0);
}

int main(int ac, char **av)
{
	char	**lst;
	t_st	*stack_a;
	size_t	i;
	t_st 	*stack_b;

	lst = NULL;
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac < 2)
		return(-1);
	if (ac == 2)
	{
		if (ft_verif(av[1]) == -1)
			return (1);
		lst = ft_split(av[1], ' ');
		if (!lst)
			return -1;
		stack_a = ft_init_stack(lst);
		if (!stack_a)
			return -1;
	}
	else
	{
		while (i <= (size_t)ac - 1)
		{
			if (ft_verif(av[i]) == -1)
				return (-1);
			i++;
		}
		stack_a = ft_init_stack_list(av, ac);
		if (!stack_a)
			return -1;
		ft_free_lst(lst);
	}

	if (ft_verif_sort(stack_a) == -1)
	{
		write(1, "OK\n", 3);
		ft_free_stack(stack_a);
		return 0;
	}
	stack_b = ft_init_stack_b(stack_a);
	if (!stack_b)
		return (-1);
	// len_five(stack_a, stack_b);
	stack_a = ft_init_sort_stack(stack_a);
	if (!stack_a)
		return -1;
	stack_a->stack_sorted = ft_quick_sort(stack_a->stack_sorted, 0, stack_a->len_max - 1);
	stack_a = ft_init_index_stack(stack_a);
	if (stack_a->error == 1)
	{
		ft_free_stack(stack_b);
		ft_free_stack(stack_a);
		return -1;
	}
	size_t id = -1;
	while( ++id  < stack_a->len_max)
	{
		printf("%zu index %d = ",id ,stack_a->index[id]);
		printf(" value %d \n",stack_a->stack_sorted[id]);
	}

	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
	return(0);
}
