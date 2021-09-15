#include "push_swap.h"

void len_three(t_st *a)
{
    if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2])
    {
        ft_swap_s(a);
        write(1, "sa\n", 3);
    }
    else if (a->stack[0] > a->stack[1] && a->stack[1] > a->stack[2])
    {
        ft_swap_s(a);
        write(1, "sa\n", 3);
        ft_swap_reverse_rotate(a);
        write(1, "rra\n", 3);
    }
    else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[1])
    {
        ft_swap_rotate(a);
        write(1, "ra\n", 3);
    }  
    else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2])
    {
        ft_swap_s(a);
        write(1, "sa\n", 3);
        ft_swap_rotate(a);
        write(1, "ra\n", 3);
    }
    else
    {
        ft_swap_reverse_rotate(a);
        write(1, "rra\n", 3);
    }
}


