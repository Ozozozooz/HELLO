/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, int *counts)
{
	int	v0;
	int	v1;
	int	v2;

	v0 = (*a)->value;
	v1 = (*a)->next->value;
	v2 = (*a)->next->next->value;
	if (v0 < v2 && v2 < v1)
	{
		sa(a, counts);
		ra(a, counts);
	}
	else if (v1 < v0 && v0 < v2)
		sa(a, counts);
	else if (v2 < v0 && v0 < v1)
		rra(a, counts);
	else if (v1 < v2 && v2 < v0)
		ra(a, counts);
	else if (v2 < v1 && v1 < v0)
	{
		sa(a, counts);
		rra(a, counts);
	}
}

static int	small_min_pos(t_stack *a, int size)
{
	int		min;
	int		pos;
	int		index;

	min = a->value;
	pos = 0;
	index = 0;
	while (index < size)
	{
		if (a->value < min)
		{
			min = a->value;
			pos = index;
		}
		index++;
		a = a->next;
	}
	return (pos);
}

static int	small_is_sorted(t_stack *a, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

static void	small_rotate_to_top(t_stack **a, int pos, int size, int *counts)
{
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos--)
			rra(a, counts);
	}
	else
	{
		while (pos--)
			ra(a, counts);
	}
}

void	ft_small_algo(t_stack **a, t_stack **b, int size, int *counts)
{
	int	pos;

	if (size <= 1)
		return ;
	if (small_is_sorted(*a, size))
		return ;
	while (size > 3)
	{
		pos = small_min_pos(*a, size);
		small_rotate_to_top(a, pos, size, counts);
		pb(a, b, counts);
		size--;
	}
	if (size == 3)
		sort_three(a, counts);
	else if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a, counts);
	while (*b)
		pa(b, a, counts);
}
