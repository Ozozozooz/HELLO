/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:21:31 by booz              #+#    #+#             */
/*   Updated: 2026/06/01 22:19:34 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*st;
	const unsigned char	*st2;
	size_t				i;

	i = 0;
	st = (const unsigned char *)s1;
	st2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (st[i] != st2[i])
			return (st[i] - st2[i]);
		i++;
	}
	return (0);
}
