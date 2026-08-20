/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 01:34:12 by booz              #+#    #+#             */
/*   Updated: 2026/06/01 20:52:27 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	while (src[j] && size > 0 && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (size > i + j)
		dst[i + j] = '\0';
	while (src[j])
		j++;
	if (size <= i)
		return (j + size);
	return (i + j);
}
