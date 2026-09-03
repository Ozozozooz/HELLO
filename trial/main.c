/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:00:00 by merged            #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by merged           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stacks	st;
	int			size;

	stack_b = NULL;
	stack_a = NULL;
	init_stack_a(argc, argv, &stack_a);
	size = ft_stack_size(stack_a);
	st.a = &stack_a;
	st.b = &stack_b;
	execute_strategy(argc, argv, &st, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
