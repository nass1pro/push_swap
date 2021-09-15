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
    swap_pb(stack_b, stack_a);
	swap_pb(stack_b, stack_a);
	swap_pb(stack_b, stack_a);
	swap_pb(stack_b, stack_a);
	swap_pb(stack_b, stack_a);
	i = 0;
	printf("pb \n");
	while (i < stack_a->len_max )
	{
		printf("stack a =  %d \t stack b =  %d \n", stack_a->stack[i], stack_b->stack[i]);
		i++;
	}
	printf("pa \n\n");
	swap_pa(stack_a, stack_b);
	swap_pa(stack_a, stack_b);
	swap_pa(stack_a, stack_b);	
	swap_pa(stack_a, stack_b);
	swap_pa(stack_a, stack_b);
	i = 0;
	while (i < stack_a->len_max)
	{
		printf("stack a =  %d \t stack b =  %d \n", stack_a->stack[i], stack_b->stack[i]);
		i++;
	}
}