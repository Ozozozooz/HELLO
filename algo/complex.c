/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_a(t_stack **a, t_stack **b, int size, int *counts)
{
	t_partition	p;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, counts);
		return ;
	}
	p.pivot = get_pivot(*a, size);
	p.size = size;
	p.smaller = 0;
	p.bigger = 0;
	loop_a(&(t_stacks){a, b}, &p, counts);
	quick_sort_a(a, b, p.bigger, counts);
	quick_sort_b(a, b, p.smaller, counts);
}

void	quick_sort_b(t_stack **a, t_stack **b, int size, int *counts)
{
	t_partition	p;

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
	p.pivot = get_pivot(*b, size);
	p.size = size;
	loop_b(&(t_stacks){a, b}, &p, counts);
	quick_sort_a(a, b, p.bigger, counts);
	quick_sort_b(a, b, p.smaller, counts);
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
