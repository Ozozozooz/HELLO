/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 02:14:13 by booz              #+#    #+#             */
/*   Updated: 2026/06/02 19:28:18 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	indexor(char const *s1, char const *set, size_t pos, char stat)
{
	size_t	j;

	while (s1[pos])
	{
		j = 0;
		while (set[j] && s1[pos] != set[j])
			j++;
		if (set[j] == '\0')
			return (pos);
		if (stat == '+')
			pos++;
		else if (stat == '-')
		{
			if (pos == 0)
				return (0);
			pos--;
		}
	}
	return (pos);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	n;
	char	*p;

	n = 0;
	if (!s1 || !set)
		return (NULL);
	start = indexor(s1, set, 0, '+');
	end = indexor(s1, set, ft_strlen(s1) - 1, '-');
	if (s1[0] == '\0' || end < start)
		return (ft_strdup(""));
	p = malloc(end - start + 2);
	if (!p)
		return (NULL);
	while (start + n <= end)
	{
		p[n] = s1[start + n];
		n++;
	}
	p[n] = '\0';
	return (p);
}
/*
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *s = "   hello world   ";
    char *set = " ";

    char *res = ft_strtrim(s, set);

    printf("%s\n", res);

    free(res);
    return 0;
}*/