/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merged <merged@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_a(t_stack **a, t_stack **b, int size, int *counts)
{
	int	smaller;
	int	bigger;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, counts);
		return ;
	}
	smaller = 0;
	bigger = 0;
	loop_a(&(t_stacks){a, b},
		&(t_partition){get_pivot(*a, size), size, &smaller, &bigger}, counts);
	quick_sort_a(a, b, bigger, counts);
	quick_sort_b(a, b, smaller, counts);
}

void	quick_sort_b(t_stack **a, t_stack **b, int size, int *counts)
{
	int	smaller;
	int	bigger;

	if (size == 0)
		return ;
	if (size == 1)
	{
		pa(b, a, counts);
		return ;
	}
	if (size == 2)
	{
		if ((*b)->value < (*b)->next->value)
			sb(b, counts);
		pa(b, a, counts);
		pa(b, a, counts);
		return ;
	}
	loop_b(&(t_stacks){a, b},
		&(t_partition){get_pivot(*b, size), size, &smaller, &bigger}, counts);
	quick_sort_a(a, b, bigger, counts);
	quick_sort_b(a, b, smaller, counts);
}

int	get_pivot(t_stack *a, int size)
{
	int	*stackar;
	int	median;

	stackar = malloc(sizeof(int) * size);
	if (!stackar)
		return (0);
	median = pivot_loop(a, stackar, size);
	free(stackar);
	return (median);
}
