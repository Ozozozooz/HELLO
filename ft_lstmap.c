/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: booz <booz@student.42.fr>                  +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/06/01 20:12:14 by booz              #+#    #+#             */
/*   Updated: 2026/06/01 20:12:14 by booz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lsto;
	t_list	*tmp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	lsto = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			del(content);
			ft_lstclear(&lsto, del);
			return (NULL);
		}
		tmp->next = NULL;
		if (!lsto)
			lsto = tmp;
		else
			ft_lstlast(lsto)->next = tmp;
		lst = lst->next;
	}
	return (lsto);
}
/*
#include "libft.h"
#include <stdio.h>


void	*f(void *c){ return (c); }
void	del(void *c){ (void)c; }

int	main(void)
{
	t_list *l = 0;
	t_list *m;

	ft_lstadd_back(&l, ft_lstnew("a"));
	ft_lstadd_back(&l, ft_lstnew("b"));

	m = ft_lstmap(l, f, del);

	while (m)
	{
		printf("%s\n", (char *)m->content);
		m = m->next;
	}
}*/