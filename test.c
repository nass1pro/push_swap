#include "push_swap.h"

void visual_stack(t_st *stack_a, t_st *stack_b)
{
    size_t i = 0;
    while (i < stack_a->len_max)
	{
		printf("stack a =  %d \t stack b =  %d \n", stack_a->stack[i], stack_b->stack[i]);
		i++;
	}
}

void test_stack(t_st *stack_a, t_st *stack_b)
{
    size_t i;
    ft_swap_pb(stack_b, stack_a);
	ft_swap_pb(stack_b, stack_a);
	ft_swap_pb(stack_b, stack_a);
	ft_swap_pb(stack_b, stack_a);
	ft_swap_pb(stack_b, stack_a);
	i = 0;
	printf("pb \n");
	while (i < stack_a->len_max )
	{
		printf("stack a =  %d \t stack b =  %d \n", stack_a->stack[i], stack_b->stack[i]);
		i++;
	}
	printf("pa \n\n");
	ft_swap_pa(stack_a, stack_b);
	ft_swap_pa(stack_a, stack_b);
	ft_swap_pa(stack_a, stack_b);	
	ft_swap_pa(stack_a, stack_b);
	ft_swap_pa(stack_a, stack_b);
	i = 0;
	while (i < stack_a->len_max)
	{
		printf("stack a =  %d \t stack b =  %d \n", stack_a->stack[i], stack_b->stack[i]);
		i++;
	}
}