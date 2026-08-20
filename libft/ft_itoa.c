/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:47:14 by booz              #+#    #+#             */
/*   Updated: 2026/06/01 20:47:14 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digits(int n)
{
	int	d;

	d = 1;
	if (n < 0)
		d++;
	while (n / 10)
	{
		n = n / 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	char	*d;
	int		i;
	long	nb;

	nb = n;
	i = digits(n);
	d = malloc(i + 1);
	if (!d)
		return (NULL);
	d[i] = '\0';
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
	{
		d[0] = '0';
		return (d);
	}
	while (nb > 0)
	{
		d[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		d[0] = '-';
	return (d);
}
/*#include <stdio.h>

char *ft_itoa(int n);

int main(void)
{
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(42));
    printf("%s\n", ft_itoa(-42));
    printf("%s\n", ft_itoa(2147483647));
    printf("%s\n", ft_itoa(-2147483648));
    return 0;
}*/
