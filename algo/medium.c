/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merged <merged@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_algo(t_stack **a, t_stack **b, int n, int *counts)
{
	t_info	info;

	if (n <= 1)
		return ;
	heap_utils(a, n);
	info.count = n;
	info.k = chunk_count(n);
	chunk_sort(a, b, &info, counts);
}

void	chunk_sort(t_stack **a, t_stack **b, t_info *info, int *counts)
{
	t_a_state	st;
	int			chunk;
	int			base;
	int			extra_chunks;

	st.a = a;
	st.size = info->count;
	st.tail = find_tail(*a);
	base = info->count / info->k;
	extra_chunks = info->count % info->k;
	info->low = 0;
	chunk = 0;
	while (chunk < info->k)
	{
		info->ch_size = base + (chunk < extra_chunks);
		info->up = info->low + info->ch_size;
		process_chunk(&st, b, info, counts);
		info->low = info->up;
		chunk++;
	}
	while (*b)
		pa(b, a, counts);
}

void	process_chunk(t_a_state *st, t_stack **b, t_info *info, int *counts)
{
	int	remaining;

	remaining = info->ch_size;
	info->pos = 0;
	while (remaining > 0)
	{
		move_one(st, b, info, counts);
		info->pos++;
		remaining--;
	}
}

void	move_one(t_a_state *st, t_stack **b, t_info *info, int *counts)
{
	t_target	tgt;
	int			depth;
	int			cost_a;
	int			reverse_b;
	t_move_ctx	ctx;

	if (!compute_dist(st, info, &tgt))
		return ;
	cost_a = tgt.pos;
	if (st->size - tgt.pos < cost_a)
		cost_a = st->size - tgt.pos;
	depth = insertion_depth(*b, info->pos, tgt.index);
	reverse_b = depth;
	ctx.forward = (cost_a == tgt.pos);
	ctx.cost_a = &cost_a;
	ctx.depth = &depth;
	rotate_extraction(st, b, &ctx, counts);
	while (depth-- > 0)
		rb(b, counts);
	pb(st->a, b, counts);
	st->size--;
	while (reverse_b-- > 0)
		rrb(b, counts);
}

int	compute_dist(t_a_state *st, t_info *info, t_target *tgt)
{
	t_stack	*front;
	t_stack	*back;
	int		pos_f;
	int		pos_b;

	pos_b = 0;
	front = scan_front(*st->a, info, &pos_f);
	if (!front)
		return (0);
	back = scan_back(st->tail, info, &pos_b);
	if (pos_b < pos_f)
	{
		tgt->pos = st->size - pos_b;
		tgt->index = back->index;
	}
	else
	{
		tgt->pos = pos_f;
		tgt->index = front->index;
	}
	return (1);
}
