/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:41:48 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 23:13:47 by nahaddac         ###   ########.fr       */
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
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}
