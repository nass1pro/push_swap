

#include "push_swap.h"

t_st *ft_init_stack_list(char **a, int ac)
{
	int	i;
	t_st	*stack_a;

	i = 1;
	stack_a = malloc(sizeof(t_st) * 1);
	stack_a->stack = malloc(sizeof(int) * ac);
	if (!stack_a || !stack_a->stack)
	{
		ft_free(NULL, stack_a->stack);
		return (NULL);
	}
	while(i <= (ac - 1))
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
	stack_a = malloc(sizeof(t_st) * 1);
	stack_a->stack = malloc(sizeof(int) * len + 1);
	if (!stack_a || !stack_a->stack)
	{
		ft_free(lst, stack_a->stack);
		return (NULL);
	}
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
	return(stack_a);
}

t_st *ft_init_stack_b(t_st *a)
{
	t_st *stack_b;

    stack_b = NULL;
	stack_b = ft_alloc_stack(stack_b, a);
    if (!stack_b)
        return (NULL);
	stack_b->len = 0;
	stack_b->len_max = a->len_max;
	return (stack_b);
}

t_st    *ft_alloc_stack(t_st *st, t_st *a)
{
    st = malloc(sizeof(t_st));
    if (st)
    {
        st->stack = malloc(sizeof(int) * a->len_max);
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
    free(a);
}