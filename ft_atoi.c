/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:46:57 by booz              #+#    #+#             */
/*   Updated: 2026/06/02 18:48:55 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	dig;

	i = 0;
	j = 1;
	dig = 0;
	while ((nptr[i] && nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			j = -j;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		dig = dig * 10 + nptr[i] - '0';
		i++;
	}
	return (dig * j);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    const char *tests[] = {
        "0",
        "42",
        "-42",
        "+42",
        "   42",
        "\t\n  42",
        "4193 with words",
        "words 42",
        "--42",
        "++42",
        "+-42",
        "-+42",
        "2147483647",
        "-2147483648",
        "2147483648",
        "-2147483649",
        "",
        "   ",
        NULL
    };

    int i = 0;

    while (tests[i] != NULL)
    {
        int lib = atoi(tests[i]);
        int mine = ft_atoi(tests[i]);

        printf("Input: \"%s\"\n", tests[i]);
        printf("atoi   : %d\n", lib);
        printf("ft_atoi: %d\n", mine);

        if (lib == mine)
            printf("OK\n\n");
        else
            printf("DIFF!\n\n");

        i++;
    }

    return 0;
}*/