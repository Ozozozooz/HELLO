/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 23:32:25 by booz              #+#    #+#             */
/*   Updated: 2026/06/02 18:21:20 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (NULL);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if ((uintptr_t)d < (uintptr_t)s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
