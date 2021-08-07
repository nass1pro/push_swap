/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:59:40 by nahaddac          #+#    #+#             */
/*   Updated: 2021/06/23 10:59:43 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct       s_st
{
    int     *stack;
    int     first;
    int     end;
    int     len;
    int     len_max;
}           t_st;

int				ft_atoi(const char *str);
char			**ft_split(char const *str, char charset);


int             ft_free(char **lst, int *num);
int             ft_free_lst(char **lst);
size_t	        ft_strlen(const char *str);
int		        ft_isdigit(int c);

// swap 

t_st *swap_s(t_st *s);

