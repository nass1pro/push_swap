/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:41:48 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/19 19:58:29 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	ft_free_is_b(t_st *a)
{
	free(a->stack);
	free(a);
	return (1);
}

int	ft_verif(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		if (str[i] == '+')
			i++;
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}
