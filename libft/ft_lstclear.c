/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:29:34 by ybendavi          #+#    #+#             */
/*   Updated: 2021/10/19 13:29:37 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (*lst)
	{
		while (*lst != NULL)
		{
			if ((*lst)->content)
				(*del)((*lst)->content);
			ptr = (*lst)->next;
			(*del)(*lst);
			*lst = ptr;
		}
	}
}
