/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merged <merged@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_a(t_stacks *st, t_partition *p, int *counts)
{
	int	i;
	int	size;

	size = p->size;
	while (size--)
	{
		if ((*st->a)->value < p->pivot)
		{
			pb(st->a, st->b, counts);
			(*p->smaller)++;
		}
		else
		{
			ra(st->a, counts);
			(*p->bigger)++;
		}
	}
	i = *p->bigger;
	while (i--)
		rra(st->a, counts);
}

void	loop_b(t_stacks *st, t_partition *p, int *counts)
{
	int	i;

	*p->smaller = 0;
	*p->bigger = 0;
	i = p->size;
	while (i--)
	{
		if ((*st->b)->value > p->pivot)
		{
			pa(st->b, st->a, counts);
			(*p->bigger)++;
		}
		else
		{
			rb(st->b, counts);
			(*p->smaller)++;
		}
	}
	i = *p->smaller;
	while (i--)
		rrb(st->b, counts);
}

int	pivot_loop(t_stack *a, int *stackar, int size)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		key;

	stackar[0] = a->value;
	tmp = a->next;
	i = 1;
	while (i < size)
	{
		key = tmp->value;
		j = i - 1;
		while (j >= 0 && stackar[j] > key)
		{
			stackar[j + 1] = stackar[j];
			j--;
		}
		stackar[j + 1] = key;
		tmp = tmp->next;
		i++;
	}
	return (stackar[(size - 1) / 2]);
}
