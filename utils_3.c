/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:44:45 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 22:59:06 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_doublon(int *s, size_t len)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < (int)len - 1)
	{
		j = 0;
		count = 0;
		while (j <= (int)len - 1)
		{
			if (s[j] == s[i])
				count++;
			j++;
		}
		if (count >= 2)
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_stack_end(t_st *a, t_st *b)
{
	free(a->stack);
	free(a->stack_sorted);
	free(b->stack);
	free(a);
	free(b);
}

int	ft_one_no_start(t_st *stack_a, char c)
{
	if (stack_a->len_max < 2)
	{
		free(stack_a->stack);
		free(stack_a);
		if (ft_isdigit(c))
			return (1);
		return (write(1, "Error\n", 6));
	}
	return (0);
}

t_st	*ft_elmain(int ac, char **av, t_st *stack_a)
{
	if (ft_multi_arg_verif(ac, av) == -1)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	stack_a = ft_init_stack_list(av, ac, stack_a);
	if (!stack_a)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	return (stack_a);
}
