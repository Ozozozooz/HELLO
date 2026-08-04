#include "pushswap.h"

void	quick_sort_b(t_stack **a, t_stack **b, int size);
void	quick_sort_a(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	smaller;
	int	bigger;

	if (size <= 1)
		return ;
	pivot = get_pivot(*a, size);
    printf("size=%d pivot=%d\n", size, pivot);
	smaller = 0;
	bigger = 0;
    if (size == 2)
	    {
		    if ((*a)->value > (*a)->next->value)
			    sa(a);
		    return ;
	    }
	while (size--)
	{
		if ((*a)->value < pivot)
		{
			pb(a, b);
			 smaller++;
		} 
		else
		{
			ra(a);
			bigger++;
		}
	}
	quick_sort_a(a, b, bigger);
	quick_sort_b(a, b, smaller);
}


void	quick_sort_b(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	smaller;
	int	bigger;

    if (size == 0)
        return;
    if (size == 1)
    {
        pa(b, a);
        return;
    }
    if (size == 2)
    {
        if ((*b)->value < (*b)->next->value)
            sb(b);
        pa(b, a);
        pa(b, a);
        return ;
    }
	pivot = get_pivot(*b, size);
    printf("size=%d pivot=%d\n", size, pivot);
	smaller = 0;
	bigger = 0;

	while (size--)
	{
		if ((*b)->value > pivot)
		{
			pa(b, a);
			bigger++;
		}
		else
		{
			rb(b);
			smaller++;
		}
	}


quick_sort_a(a, b, bigger);
quick_sort_b(a, b, smaller);
}

int	find_max_val(t_stack *a, int size)
{
	int	max;

	max = a->value;
	while (--size)
	{
        a=a->next;
		if (a->value > max)
			max = a->value;
	}
	return (max);
}

int	find_min_val(t_stack *a, int size)
{
	int	min;

	min = a->value;
	while (--size)
	{
        a=a->next;
		if (a->value < min)
			min = a->value;
	}
	return (min);
}

int	get_pivot(t_stack *a, int size)
{
	long	min;
	long	max;

	min = find_min_val(a, size);
	max = find_max_val(a, size);

	return ((int)((min + max) / 2));
}