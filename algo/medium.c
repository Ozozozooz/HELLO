
#include "pushswap.h"

void	medium_algo(t_stack **a, t_stack **b, int argc, int *counts)
{
	t_info	c_info;
	int		size;

	heap_utils(a, argc);
	size = ft_stack_size(*a);
	c_info.k = root(size);
	c_info.low = size - 1;
	c_info.up = c_info.low - c_info.k + 1;
	c_info.count = c_info.k;
	while (c_info.up >= 0 && c_info.count != 0)
		process_chunk(a, b, &c_info, size, counts);
}

void	process_chunk(t_stack **a, t_stack **b, t_info *c_info, int size,
		int *counts)
{
	int	pos;

	while (c_info->count != 0)
	{
		pos = find_chunk_pos(*a, c_info, size);
		if (pos >= 0)
		{
			while (pos--)
				ra(a, counts);
		}
		else
		{
			while (pos++)
				rra(a, counts);
		}
		pb(a, b, counts);
		size--;
		c_info->count--;
		if (c_info->count == 0)
		{
			next_chunk(c_info, b, a, counts);
			size = ft_stack_size(*a);
		}
	}
}

int	find_chunk_pos(t_stack *a, t_info *c_info, int size)
{
	t_stack	*temp;
	int		pos;

	temp = a;
	pos = 0;
	while (temp)
	{
		if (temp->index >= c_info->up
			&& temp->index <= c_info->low)
			break ;
		pos++;
		temp = temp->next;
	}
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	next_chunk(t_info *c_info, t_stack **b, t_stack **a, int *counts)
{
	c_info->up -= c_info->k;
	c_info->low -= c_info->k;
	c_info->count = c_info->k;

	intermittent_bsort(b, a, c_info, counts);
	if (c_info->up < 0)
	{
		c_info->up = 0;
		c_info->k = c_info->low + 1;
		c_info->count = c_info->k;
	}
}

void	intermittent_bsort(t_stack **b, t_stack **a, t_info *c_info,
		int *counts)
{
	t_stack	*temp;
	t_stack	*big;
	int		i;
	int		big_pos;

	while (*b)
	{
		temp = *b;
		big = *b;
		big_pos = 0;
		i = 0;
		while (i < c_info->k && temp->next)
		{
			if (big->index < temp->next->index)
			{
				big = temp->next;
				big_pos = i + 1;
			}
			temp = temp->next;
			i++;
		}
		sort_to_a(big_pos, i + 1, b, a, counts);
	}
}

void	sort_to_a(int pos, int size, t_stack **b, t_stack **a, int *counts)
{
	if (pos >= size / 2)
	{
		pos = size - pos;
		while (pos--)
			rrb(b, counts);
	}
	else
	{
		while (pos--)
			rb(b, counts);
	}
	pa(b, a, counts);
}
