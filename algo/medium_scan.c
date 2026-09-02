/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merged <merged@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*scan_front(t_stack *head, t_info *info, int *pos_f)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->index >= info->low && head->index < info->up)
		{
			*pos_f = i;
			return (head);
		}
		i++;
		head = head->next;
	}
	return (NULL);
}

t_stack	*scan_back(t_stack *tail, t_info *info, int *pos_b)
{
	int	i;

	i = 1;
	while (tail)
	{
		if (tail->index >= info->low && tail->index < info->up)
		{
			*pos_b = i;
			return (tail);
		}
		i++;
		tail = tail->prev;
	}
	return (NULL);
}

int	insertion_depth(t_stack *b, int placed, int index)
{
	int		d;
	t_stack	*node;

	d = 0;
	node = b;
	while (node && placed-- > 0)
	{
		if (node->index < index)
			break ;
		d++;
		node = node->next;
	}
	return (d);
}

void	rotate_extraction(t_a_state *st, t_stack **b, t_move_ctx *ctx,
			int *counts)
{
	if (ctx->forward)
		merge_forward(st, b, ctx, counts);
	else
	{
		while ((*ctx->cost_a)-- > 0)
		{
			st->tail = st->tail->prev;
			rra(st->a, counts);
		}
	}
}

void	merge_forward(t_a_state *st, t_stack **b, t_move_ctx *ctx, int *counts)
{
	int	merged;

	merged = *ctx->cost_a;
	if (*ctx->depth < merged)
		merged = *ctx->depth;
	*ctx->cost_a -= merged;
	*ctx->depth -= merged;
	while (merged-- > 0)
	{
		st->tail = *st->a;
		rr(st->a, b, counts);
	}
	while ((*ctx->cost_a)-- > 0)
	{
		st->tail = *st->a;
		ra(st->a, counts);
	}
}
