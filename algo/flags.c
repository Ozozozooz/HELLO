/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merged <merged@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *str)
{
	return (str[0] == '-' && str[1] == '-');
}

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	is_algo_flag(char *s)
{
	return (strcmp(s, "--simple") == 0 || strcmp(s, "--medium") == 0
		|| strcmp(s, "--complex") == 0 || strcmp(s, "--adaptive") == 0);
}

int	leading_flags(int argc, char **argv, int *bench, char **algo)
{
	int	n;

	*bench = 0;
	*algo = NULL;
	n = 0;
	if (argc > 1 && strcmp(argv[1], "--bench") == 0)
	{
		*bench = 1;
		n = 1;
		if (argc > 2 && is_algo_flag(argv[2]))
		{
			*algo = argv[2];
			n = 2;
		}
	}
	else if (argc > 1 && is_algo_flag(argv[1]))
	{
		*algo = argv[1];
		n = 1;
	}
	else if (argc > 1 && is_flag(argv[1]))
		ft_error_exit();
	return (n);
}
