/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:57:03 by booz              #+#    #+#             */
/*   Updated: 2026/06/02 19:41:29 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && little[j])
			j++;
		if (little[j] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
/*
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *s = "hello world";
    char *find = "world";

    printf("%s\n", ft_strnstr(s, find, 11));

    return 0;
}
*/