/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merged <merged@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*path_name(int path)
{
	if (path <= 3)
		return ("Adaptive");
	if (path == 4)
		return ("Simple");
	if (path == 5)
		return ("Medium");
	return ("Complex");
}

char	*path_class(int path)
{
	if (path == 1 || path == 4)
		return ("O(n\xc2\xb2)");
	if (path == 2 || path == 5)
		return ("O(n\xe2\x88\x9an)");
	return ("O(n log n)");
}

int	sum_ops(int *counts)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < 11)
		total += counts[i++];
	return (total);
}
