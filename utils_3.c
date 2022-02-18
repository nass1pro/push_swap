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

int check_doublon(int *s, size_t len)
{
	int i;
	int j;
	int count;

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

void ft_free_stack_end(t_st *a, t_st *b)
{
	free(a->stack);
	free(a->stack_sorted);
	free(b->stack);
	free(a);
	free(b);
}