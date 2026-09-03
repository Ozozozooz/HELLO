/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sradhakr <sradhakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_count(int n)
{
	int	x;

	x = 0;
	while ((x + 1) * (x + 1) <= n)
		x++;
	return ((x * 116 + 50) / 100);
}

t_stack	*find_tail(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}
