/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:37:42 by nahaddac          #+#    #+#             */
/*   Updated: 2021/06/23 12:37:44 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_verif_sort(t_st *a)
{
	size_t i;
	size_t v;
	size_t t;

	i = 0;
	v = 1;
	t = 0;
	while (v < a->len_max)
	{
		if (a->stack[i] >= a->stack[v])
			return 0;
		i++;
		v++;
	}
	return -1;
}

int ft_verif(char *str)
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

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int ft_free_lst(char **lst)
{
	if (lst)
		while (lst)
		{
			free(*lst);
			lst++;
		}
	return (0);
}

int ft_free(char **lst, int *num)
{
	if (num)
	{
		free(num);
	}
	ft_free_lst(lst);
	return (-1);
}

