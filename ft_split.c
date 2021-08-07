/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:59:56 by nahaddac          #+#    #+#             */
/*   Updated: 2019/10/25 12:01:51 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		*print_str(char const *str, int size, int j, char **cp)
{
	int			i;

	i = 0;
	cp[j] = malloc(sizeof(char) * (size + 1));
	if (cp[j] == NULL)
	{
		j = 0;
		while (cp[j])
			free(cp[j++]);
		return (0);
	}
	while (i < size)
	{
		cp[j][i] = str[i];
		i++;
	}
	cp[j][i] = '\0';
	return (cp[j]);
}

static char		**ft_str_is_free(char **cp)
{
	free(cp);
	return (NULL);
}

static int		ft_sp(char const *str, char charset)
{
	const char	*word;
	int			j;

	j = 0;
	word = str;
	while (*str)
	{
		if (charset == *str)
		{
			if (str - word > 0)
				j++;
			word = str + 1;
		}
		str++;
	}
	if (str - word > 0)
		j++;
	return (j);
}

static char		**ft_split_2(char const *str, char ch, char const *w, char **cp)
{
	int			j;

	j = 0;
	while (*str)
	{
		if (ch == *str)
		{
			if (str - w > 0)
			{
				if (!(cp[j] = print_str(w, str - w, j, cp)))
					return (ft_str_is_free(cp));
				j++;
			}
			w = str + 1;
		}
		str++;
	}
	if (str - w > 0)
	{
		print_str(w, str - w, j, cp);
		j++;
	}
	cp[j] = 0;
	return (cp);
}

char			**ft_split(char const *str, char charset)
{
	int			i;
	char		**cp;
	char const	*word;
	char		**c;

	cp = NULL;
	c = NULL;
	i = 0;
	c = malloc(sizeof(char *) * (i));
	if (c == NULL)
		return (0);
	if (str == 0 || *str == '\0' || charset == 0)
	{
		c[0] = 0;
		return (c);
	}
	i = ft_sp(str, charset);
	cp = malloc(sizeof(char *) * (i + 1));
	if (cp == NULL)
		return (0);
	word = str;
	if (str)
		return (ft_split_2(str, charset, word, cp));
	return (0);
}
