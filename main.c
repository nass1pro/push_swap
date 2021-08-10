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
	stack_a->stack = malloc(sizeof(int) * (ac - 1));
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
	return(stack_a);
}

static t_st *init_stack(char **lst)
{
	size_t	i;
	size_t	len;
	t_st	*stack_a;

	i = 0;
	len = 0;

	while (lst[len] != NULL)
		len++;
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
		if (i == 0)
		{
			stack_a->first = ft_atoi(lst[i]);
		}
		if (lst[i])
			stack_a->stack[i] = ft_atoi(lst[i]);
		i++;
	}

	stack_a->end = len;
	stack_a->len = len;
	stack_a->len_max = len;
	return(stack_a);
}

int main(int ac, char **av)
{
	char	**lst;
	t_st	*stack_a;
	int i = 1;
	lst = NULL;

	stack_a = NULL;
	if (ac < 2)
		return(-1);
	if (ac == 2)
	{
		if (ft_verif(av[1]) == -1)
		{
			return (-1);
		}
		lst = ft_split(av[1], ' ');
		i = 0;
		stack_a = init_stack(lst);
	}
	else
	{
		while (i <= ac - 1)
		{
			if (ft_verif(av[i]) == -1)
				return (-1);
			i++;
		}
		stack_a = init_stack_list(av, ac);
		ft_free_lst(lst);
	}
	i = 0;
	while (i < stack_a->len)
	{
		printf("%d \n", stack_a->stack[i]);
		i++;
	}
	return(0);
}
