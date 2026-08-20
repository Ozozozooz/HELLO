#include "pushswap.h"

/*float	compute_disorder(t_stack *a)
{
	float		mistake;
	float		pair;
	t_stack		*i;
	t_stack		*j;
	int			size;

	mistake = 0;
	size = ft_stack_size(a);
	i = a;
	pair = size * (size -1) / 2;
	while (i)
	{
		j = i -> next;
		while (j)
		{
			if (i->value > j->value)
				mistake += 1;
			j = j ->next;
		}
		i = i ->next;
	}
	printf("\nDisorder is %lf \n", mistake / pair);
	return (mistake / pair);
}*/

//ROOT

int	root(int num)
{
	int	base;
	int	k;

    base = ft_isqrt(num);
    if (num <= 20)
        k = base;
    else
        k = (base * 265) / 100;
    if (k < 1)
        k = 1;
    return (k);
}

int	ft_isqrt(int n)
{
	int	i;

	if (n < 0)
		return (0);
	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}