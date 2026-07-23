/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/06/01 19:58:29 by booz              #+#    #+#             */
/*   Updated: 2026/06/01 19:58:29 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	c = malloc(ft_strlen(s) + 1);
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
/*
#include "libft.h"
#include <stdio.h>

char f(unsigned int i, char c)
{
    (void)i;
    return c + 1;
}

int main(void)
{
    char *s = "abc";
    char *res = ft_strmapi(s, f);

    printf("%s\n", res);

    free(res);
    return 0;
}
*/