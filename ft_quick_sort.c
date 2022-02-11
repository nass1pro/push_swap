/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahaddac <nahaddac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:59:19 by nahaddac          #+#    #+#             */
/*   Updated: 2021/08/07 15:34:39 by nahaddac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*ft_swap(int *stack, int i, int j)
{
	int	tmp;

	tmp = stack[i];
	stack[i] = stack[j];
	stack[j] = tmp;
	return (stack);
}

static int	ft_partition(int *arr, int low, int higth)
{
	int	i;
	int	pivot;
	int	j;

	i = low - 1;
	pivot = arr[higth];
	j = low;
	while (j < higth)
	{
		if (arr[j] < pivot)
		{
			i++;
			arr = ft_swap(arr, i, j);
		}
		j++;
	}
	arr = ft_swap(arr, i + 1, higth);
	return (i + 1);
}

int	*ft_quick_sort(int *arr, int low, int higth)
{
	int	part_i;

	if (low < higth)
	{
		part_i = ft_partition(arr, low, higth);
		ft_quick_sort(arr, low, part_i - 1);
		ft_quick_sort(arr, part_i + 1, higth);
	}
	return (arr);
}
