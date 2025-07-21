/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:31:10 by ybendavi          #+#    #+#             */
/*   Updated: 2021/10/19 13:33:15 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mapping(t_list *lst, t_list *new, void *(*f)(void *))
{		
	while (lst)
	{
		new->next = malloc(sizeof(t_list *));
		new = new->next;
		new->content = (*f)(lst->content);
		lst = lst->next;
	}
	new->next = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	(void)del;
	new = NULL;
	if (lst)
	{
		new = malloc(sizeof(lst));
		if (!new)
			return (NULL);
		new->content = (*f)(lst->content);
		lst = lst->next;
		mapping(lst, new, f);
	}
	return (new);
}
