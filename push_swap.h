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
#include <unistd.h>

typedef struct       s_st
{
    int         *stack;
    int         first;
    int         end;
    size_t      len;
    size_t      len_max;
}           t_st;

int				ft_atoi(const char *str);
char			**ft_split(char const *str, char charset);


int             ft_free(char **lst, int *num);
int             ft_free_lst(char **lst);
size_t	        ft_strlen(const char *str);
int		        ft_isdigit(int c);


// init_stack.c
t_st            *ft_init_stack_b(t_st *stack_a);
t_st            *ft_init_stack(char **lst);
t_st            *ft_init_stack_list(char **a, int ac);
void            ft_free_stack(t_st *a);
t_st            *ft_alloc_stack(t_st *st, int len);


// swap.c
int	            ft_swap_rotate(t_st *s);
int	            ft_swap_reverse_rotate(t_st *s);
int	            ft_swap_pa(t_st *a, t_st *b);
int             ft_swap_s(t_st *s);
int	            ft_swap_pb(t_st *b, t_st *a);

//test.c delete file when close the project on intra 
void test_stack(t_st *stack_a, t_st *stack_b);
void visual_stack(t_st *stack_a, t_st *stack_b);

// sort.c

void            ft_len_three(t_st *a);
