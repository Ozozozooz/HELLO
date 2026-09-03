/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_selected(char *algo, t_stacks *st, int size, int *counts)
{
	if (size <= 5)
	{
		counts[11] = 7;
		ft_small_algo(st->a, st->b, size, counts);
		return ;
	}
	if (algo && strcmp(algo, "--simple") == 0)
	{
		counts[11] = 4;
		ft_simple_algo(st->a, st->b, counts);
	}
	else if (algo && strcmp(algo, "--medium") == 0)
	{
		counts[11] = 5;
		medium_algo(st->a, st->b, size, counts);
	}
	else if (algo && strcmp(algo, "--complex") == 0)
	{
		counts[11] = 6;
		quick_sort_a(st->a, st->b, size, counts);
	}
	else
		ft_adaptive(st->a, st->b, size, counts);
}

void	execute_strategy(int argc, char **argv, t_stacks *st, int size)
{
	int		i;
	int		counts[12];
	int		bench;
	char	*algo;
	double	disorder;

	ft_bzero(counts, sizeof(counts));
	i = 1 + leading_flags(argc, argv, &bench, &algo);
	while (i < argc)
	{
		if (is_flag(argv[i]))
			ft_error_exit();
		i++;
	}
	disorder = 0.0;
	if (bench)
		disorder = ft_disorder(*st->a, size);
	run_selected(algo, st, size, counts);
	if (bench)
		print_bench(disorder, counts);
}
