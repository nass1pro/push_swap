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
        write(1, "rra\n", 4);
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
        write(1, "rra\n", 4);
    }
}

// void len_five(t_st *a, t_st *b)
// {
//     // ft_swap_pa(b, a);
//     // ft_swap_pa(b, a);
//     // len_three(a);
//     // ft_swap_pb(a, b);
//     // if (a->stack[0] > a->stack[a->len])
//     //     ft_swap_rotate(a);
    
//     //j'ai une autre idée :D
// }
