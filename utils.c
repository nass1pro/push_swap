/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:37:42 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 17:04:35 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_multi_arg_verif(int ac, char **av)
{
	int	i;

	i = 1;
	while (i <= ac - 1)
	{
		if (ft_verif(av[i]) == -1)
			return (-1);
		if  (ft_strchr(av[i], ' ') == 1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_write_error(t_st *stack)
{
	write(1, "Error\n", 6);
	if (stack)
		ft_free_stack(stack);
	return (-1);
}

int	ft_strchr(const char *s, int c)
{
    int    i;

    i = 0;
    while (s[i] && s[i] != (char)c)
        i++;
    if (s[i] == (char)c)
        return (1);
    return (0);
}

int	ft_verif_sort(t_st *a)
{
	size_t	i;
	size_t	v;

	i = 0;
	v = 1;
	while (v < a->len_max)
	{
		if (a->stack[i] >= a->stack[v])
			return (0);
		i++;
		v++;
	}
	return (1);
}

int ft_test_sort(t_st *a)
{
	size_t i = 0;
	size_t v = 1;
	while (v < a->len)
	{
		if (a->stack[i] >= a->stack[v])
			return (1);
		i++;
		v++;
	}
	return 0;
}

int	ft_verif(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{

		if (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
			
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_free_lst(char **lst)
{
	if (lst)
	{
		while (lst)
		{
			free(*lst);
			lst++;
		}
	}
	return (0);
}

int	ft_free(char **lst, int *num)
{
	if (num)
		free(num);
	ft_free_lst(lst);
	return (-1);
}
