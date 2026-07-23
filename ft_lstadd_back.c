/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 20:25:42 by booz              #+#    #+#             */
/*   Updated: 2026/06/01 20:25:42 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

/*
#include "libft.h"
#include <stdio.h>

int main(void)
{
    t_list *l = NULL;

    ft_lstadd_back(&l, ft_lstnew("a"));
    ft_lstadd_back(&l, ft_lstnew("b"));

    while (l)
    {
        printf("%s\n", (char *)l->content);
        l = l->next;
    }
}*/