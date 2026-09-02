/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merged <merged@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_percent(double val, int fd)
{
	int	whole;
	int	frac;

	if (val < 0)
		val = 0;
	whole = (int)val;
	frac = (int)((val - whole) * 100 + 0.5);
	if (frac >= 100)
	{
		frac -= 100;
		whole += 1;
	}
	ft_putnbr_fd(whole, fd);
	ft_putchar_fd('.', fd);
	if (frac < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(frac, fd);
	ft_putchar_fd('%', fd);
}

static void	put_pair(char *label, int value, int fd, int last)
{
	ft_putstr_fd(label, fd);
	ft_putstr_fd(": ", fd);
	ft_putnbr_fd(value, fd);
	if (!last)
		ft_putstr_fd("  ", fd);
}

static void	print_ops1(int *counts)
{
	ft_putstr_fd("[bench] ", 2);
	put_pair("sa", counts[SA], 2, 0);
	put_pair("sb", counts[SB], 2, 0);
	put_pair("ss", counts[SS], 2, 0);
	put_pair("pa", counts[PA], 2, 0);
	put_pair("pb", counts[PB], 2, 1);
	ft_putchar_fd('\n', 2);
}

static void	print_ops2(int *counts)
{
	ft_putstr_fd("[bench] ", 2);
	put_pair("ra", counts[RA], 2, 0);
	put_pair("rb", counts[RB], 2, 0);
	put_pair("rr", counts[RR], 2, 0);
	put_pair("rra", counts[RRA], 2, 0);
	put_pair("rrb", counts[RRB], 2, 0);
	put_pair("rrr", counts[RRR], 2, 1);
	ft_putchar_fd('\n', 2);
}

void	print_bench(double disorder, int *counts)
{
	ft_putstr_fd("[bench] disorder:  ", 2);
	put_percent(disorder * 100, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(path_name(counts[11]), 2);
	ft_putstr_fd(" / ", 2);
	ft_putendl_fd(path_class(counts[11]), 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(sum_ops(counts), 2);
	ft_putchar_fd('\n', 2);
	print_ops1(counts);
	print_ops2(counts);
}
