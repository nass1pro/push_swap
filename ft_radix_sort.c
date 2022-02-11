#include "push_swap.h"

int ft_radix(t_st *a , t_st *b)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (true)
    {
        j = 0;
        while (j < a->len)
        {
            if ((a->first >> i)&1)
                ft_swap_rotate_a(a);
            else
                ft_swap_pb(b, a);
            j++;
        }
        while(b->len)
            ft_swap_pa(a, b);
        if (ft_verif_sort(a) == -1)
            break;
        i++;
    }
}
