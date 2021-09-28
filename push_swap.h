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
    int         *index;
    int         *stack;
    int         *stack_sorted;
    int         first;
    int         end;
    size_t      len;
    size_t      len_max;
    int         error;
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
t_st            *ft_init_sort_stack(t_st *s);
t_st            *ft_init_index_stack(t_st *s);


// swap.c

int	            ft_swap_rotate(t_st *s);
int	            ft_swap_rotate_a(t_st *s);
int	            ft_swap_rotate_b(t_st *s);
int	            ft_swap_rotate_ab(t_st *a, t_st *b);

int	            ft_swap_reverse_rotate(t_st *s);
int	            ft_swap_reverse_rotate_a(t_st *s);
int	            ft_swap_reverse_rotate_b(t_st *s);
int	            ft_swap_reverse_rotate_ab(t_st *a, t_st *b);

int	            ft_swap_pa(t_st *a, t_st *b);
int	            ft_swap_pb(t_st *b, t_st *a);

int             ft_swap_s(t_st *s);
int             ft_swap_sa(t_st *a);
int             ft_swap_sb(t_st *a);
int             ft_swap_ss(t_st *a);




//test.c delete file when close the project on intra 
void test_stack(t_st *stack_a, t_st *stack_b);
void visual_stack(t_st *stack_a, t_st *stack_b);
void test_five(t_st *a, t_st *b);

// sort.c

void            ft_len_three(t_st *a);
void            len_five(t_st *a, t_st *b);

// ft_quick_sort.c

int             *ft_quick_sort(int *arr, int low, int higth);
int             *ft_swap(int *stack ,int i, int j);
