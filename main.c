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

static int ft_verif(char *str)
{
	size_t i;

	i = 0;

	while(i < ft_strlen(str))
	{
		if (str[i] == ' ')
			i++;
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return(0);
}

static t_st *init_stack_list(char **a, int ac)
{
	int	i;
	t_st	*stack_a;

	i = 1;
	stack_a = malloc(sizeof(t_st) * 1);
	stack_a->stack = malloc(sizeof(int) * ac);
	if (!stack_a || !stack_a->stack)
	{
		ft_free(NULL, stack_a->stack);
		return (NULL);
	}
	while(i <= (ac - 1))
	{
		if (i == 1)
		{
			stack_a->first = ft_atoi(a[i]);
		}
		stack_a->stack[i - 1] = ft_atoi(a[i]);
		i++;
	}
	stack_a->end = stack_a->stack[i - 1];
	stack_a->len = ac - 1;
	stack_a->len_max = ac - 1;
	return(stack_a);
}

static t_st *init_stack(char **lst)
{
	size_t	i;
	size_t	len;
	t_st	*stack_a;

	i = 0;
	len = 0;
	// 
	while (lst[len] != NULL)
	{
		len++;
	}
		

	
	stack_a = malloc(sizeof(t_st) * 1);
	stack_a->stack = malloc(sizeof(int) * len);
	if (!stack_a || !stack_a->stack)
	{
		ft_free(lst, stack_a->stack);
		return (NULL);
	}
	i = 0;
	
	while(i < len)
	{
		stack_a->stack[i] = ft_atoi(lst[i]);
		i++;
	}
	stack_a->first = stack_a->stack[0];
	stack_a->end = len;
	stack_a->len = len;
	stack_a->len_max = len;
	return(stack_a);
}

int main(int ac, char **av)
{
	char	**lst;
	t_st	*stack_a;
	size_t	i = 1;
	lst = NULL;

	stack_a = NULL;
	if (ac < 2)
		return(-1);
	if (ac == 2)
	{
		if (ft_verif(av[1]) == -1)
		{
			return (1);
		}
		lst = ft_split(av[1], ' ');
		i = 0;
		stack_a = init_stack(lst);
	}
	else
	{
		while (i <= (size_t)ac - 1)
		{
			if (ft_verif(av[i]) == -1)
				return (-1);
			i++;
		}
		stack_a = init_stack_list(av, ac);
		ft_free_lst(lst);
	}
	t_st *stack_b;
	stack_b = malloc(sizeof(t_st));
	stack_b->stack = malloc(sizeof(int) * ac);
	i = 0;
	stack_b->len = 0;
	stack_b->len_max = 0;
	// fprintf(stderr,"%d /n", stack_b->stack[0]);
	swap_pb(stack_b, stack_a);
	swap_pb(stack_b, stack_a);
	swap_pb(stack_b, stack_a);
	i = 0;
	printf("pb \n");
	while (i < stack_a->len)
	{
		printf("stack a =  %d \n", stack_a->stack[i]);
		printf("stack b = %d \n", stack_b->stack[0]);
		i++;
	}
	printf("pa \n");
	swap_pa(stack_a, stack_b);
	swap_pa(stack_a, stack_b);
	swap_pa(stack_a, stack_b);
	i = 0;
	printf("len_max A : %zu \n", stack_a->len_max);
	while (i < stack_a->len)
	{
		printf("stack a =  %d \n", stack_a->stack[i]);
		printf("stack b = %d \n", stack_b->stack[i]);
		i++;
	}
	// printf("%d \n", stack_b->stack[0]);
	free(stack_b->stack);
	free(stack_a->stack);
	free(stack_b);
	free(stack_a);
	return(0);
}
