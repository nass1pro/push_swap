

#include "push_swap.h"

t_st *ft_init_stack_list(char **a, int ac)
{
	int	i;
	t_st	*stack_a;

	i = 1;
    stack_a = NULL;
    stack_a = ft_alloc_stack(stack_a, ac);
	if (!stack_a)
        return (NULL);
	while(i <= ac - 1)
	{
		if (i == 1)
		{
			stack_a->first = ft_atoi(a[i]);
		}
		stack_a->stack[i - 1] = ft_atoi(a[i]);
		i++;
	}
	stack_a->end = stack_a->stack[i - 1];
	stack_a->len = ac - 1;
	stack_a->len_max = ac - 1;
	return(stack_a);
}

t_st *ft_init_stack(char **lst)
{
	size_t	i;
	size_t	len;
	t_st	*stack_a;

	i = 0;
	len = 0;
    stack_a = NULL;
	while (lst[len] != NULL)
	{
		len++;
	}
  stack_a = ft_alloc_stack(stack_a, len);
  if (!stack_a)
    return (NULL);
	i = 0;
	while(i < len)
	{
		stack_a->stack[i] = ft_atoi(lst[i]);
		i++;
	}
	stack_a->first = stack_a->stack[0];
	stack_a->end = len;
	stack_a->len = len;
	stack_a->len_max = len;
	stack_a->error = 0;
	return(stack_a);
}

t_st *ft_init_stack_b(t_st *a)
{
	t_st *stack_b;

  stack_b = NULL;
	stack_b = ft_alloc_stack(stack_b, a->len_max);
  if (!stack_b)
    return (NULL);
	stack_b->len = 0;
	stack_b->len_max = a->len_max;
	return (stack_b);
}

t_st    *ft_alloc_stack(t_st *st, int len_max)
{
    st = malloc(sizeof(t_st));
    if (st)
    {
        st->stack = malloc(sizeof(int) * len_max);
	    if (!st->stack)
		    return (NULL);
    }
    else
        return(NULL);
    return (st);
}

void ft_free_stack(t_st *a)
{
    free(a->stack);
	if (a->index)
		free(a->index);
	if (a->stack_sorted)
		free(a->stack_sorted);
    free(a);
}

t_st *ft_init_sort_stack(t_st *s)
{
	size_t i;

	i = -1;
	s->stack_sorted = malloc(sizeof(int) * s->len_max);
	if (!s->stack_sorted)
		return (NULL);

	while(++i < s->len_max)
		s->stack_sorted[i] = s->stack[i];
	return (s);
}

t_st 	*ft_init_index_stack(t_st *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	s->index = malloc(sizeof(int) * s->len_max);
	if (!s->index)
		return (NULL);
	while(i <= s->len_max)
	{
		while(s->stack[j] != s->stack_sorted[i])
		{
			if (s->stack_sorted[i] == s->stack_sorted[i + 1] && i < s->len_max)
			{
				s->error = 1;
				return (s);
			}
			j++;
		}
		s->index[i] = j;
		j = 0;
		i++;
	}
	return (s);
}
