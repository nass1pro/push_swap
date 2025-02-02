/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:59:40 by nahaddac          #+#    #+#             */
/*   Updated: 2022/02/19 19:51:52 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_st
{
	int		*index;
	int		*stack;
	int		*stack_sorted;
	int		first;
	int		end;
	size_t	len;
	size_t	len_max;
	int		error;
}	t_st;

long	ft_atoi(const char *str);
char	**ft_split(char const *str, char charset);
int		ft_free_is_b(t_st *a);
// utils 
int		ft_verif(char *str);
int		ft_verif_sort(t_st *a);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_strchr(const char *s, int c);
int		ft_multi_arg_verif(int ac, char **av);
int		ft_write_error(t_st *stack);
// init_stack.c
t_st	*ft_init_stack_b(t_st *stack_a);
t_st	*ft_init_stack(char **lst, t_st *stack_a);
t_st	*ft_init_stack_list(char **a, int ac, t_st *stack_a);
void	ft_free_stack(t_st *a);
t_st	*ft_alloc_stack(t_st *st, int len);
t_st	*ft_init_sort_stack(t_st *s);
t_st	*ft_init_index_stack(t_st *s);
t_st	*ft_init_arg_ac(t_st *stack_a, int ac, int i);
t_st	*ft_init_arg(t_st *stack_a, size_t len);
// swap.c
int		ft_swap_rotate(t_st *s);
int		ft_swap_rotate_a(t_st *s);
int		ft_swap_rotate_b(t_st *s);
int		ft_swap_rotate_ab(t_st *a, t_st *b);
int		ft_swap_reverse_rotate(t_st *s);
int		ft_swap_reverse_rotate_a(t_st *s);
int		ft_swap_reverse_rotate_b(t_st *s);
int		ft_swap_reverse_rotate_ab(t_st *a, t_st *b);
int		ft_swap_pa(t_st *a, t_st *b);
int		ft_swap_pb(t_st *b, t_st *a);
int		ft_swap_s(t_st *s);
int		ft_swap_sa(t_st *a);
int		ft_swap_sb(t_st *a);
int		ft_swap_ss(t_st *a);
// sort.c
void	ft_len_three(t_st *a);
void	len_five(t_st *a, t_st *b);
// ft_quick_sort.c
int		*ft_quick_sort(int *arr, int low, int higth);
int		*ft_swap(int *stack, int i, int j);
int		ft_radix(t_st *a, t_st *b);
t_st	*ft_init_radix_sort(t_st *stack_a, t_st *stack_b);
int		check_doublon(int *s, size_t len);
void	ft_free_stack_end(t_st *a, t_st *b);
t_st	*ft_elmain(int ac, char **av, t_st *stack_a);
int		ft_one_no_start(t_st *stack_a, char c);
#endif
