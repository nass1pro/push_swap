/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:44:45 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/18 20:00:34 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_doublon(int *s, size_t len)
{
	int i;
	int j;

	i = 0;
	while (s[i] != (int)len - 1)
	{
		j = -1;
		while (s[++j] != (int)len - 1)
		{
			if (i == j && j == (int)len - 1)
				j += 1;
			if (j == (int)len - 1)
				return (1);
			if (s[j] == s[i])
				return (1);
		}
		i++;
	}
	return (0);
}