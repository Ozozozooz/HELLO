/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merged <merged@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_loop(char **split_args, t_stack **stack_a)
{
	int		j;
	long	num;

	j = 0;
	while (split_args[j])
	{
		num = ft_atoi_strict(split_args[j], stack_a, split_args);
		ft_stack_add_back(stack_a, stack_new((int)num));
		j++;
	}
}

void	init_stack_a(int argc, char **argv, t_stack **stack_a)
{
	char	**split_args;
	int		i;
	int		bench;
	char	*algo;

	i = 1 + leading_flags(argc, argv, &bench, &algo);
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0' || check_spaces(argv[i]))
			ft_error(stack_a, NULL);
		split_args = ft_split(argv[i++], ' ');
		if (!split_args)
			ft_error(stack_a, NULL);
		init_loop(split_args, stack_a);
		free_string_array(split_args);
	}
	check_duplicates(stack_a);
}
