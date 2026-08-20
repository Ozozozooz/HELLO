/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 22:15:25 by booz              #+#    #+#             */
/*   Updated: 2026/06/02 23:07:28 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			mult;
	size_t			i;
	void			*ptr;
	unsigned char	*p;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (((size_t)-1) / size < nmemb)
		return (NULL);
	mult = nmemb * size;
	ptr = malloc(mult);
	if (ptr == NULL)
		return (NULL);
	p = ptr;
	i = 0;
	while (i < mult)
		p[i++] = 0;
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = calloc(3, sizeof(int));
    int i = 0;
    while (i < 3)
    {
        printf("%d ", arr[i]);
        i++;
    }

    free(arr);
    return 0;
}*/