/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 00:54:54 by booz              #+#    #+#             */
/*   Updated: 2026/06/01 20:15:32 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && size > 0 && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
