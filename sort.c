

#include "push_swap.h"

void len_three(t_st *a)
{
    if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2])
        ft_swap_s(a);
    else if (a->stack[0] > a->stack[1] && a->stack[1] > a->stack[2])
    {
        ft_swap_s(a);
        ft_swap_reverse_rotate(a);
    }
    else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[1])
        ft_swap_rotate(a);
    else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2])
    {
        ft_swap_s(a);
        ft_swap_rotate(a);
    }
    else
        ft_swap_reverse_rotate(a);
}

void len_five(t_st *a, t_st *b)
{
    int i;

    i = 0;
    ft_swap_pb(b, a)
    ft_swap_pb(b, a);
    len_three(a);

    while (b->len)
    {
        while(i < a->len && a->stack[i] < b->stack[0])
        {
            i++;
        }
    }

}


