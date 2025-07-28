/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:28:51 by ybendavi          #+#    #+#             */
/*   Updated: 2021/10/19 13:29:00 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if (*alst == NULL && new)
		ft_lstadd_front(alst, new);
	else if (*alst && new)
	{
		last = ft_lstlast(*alst);
		last->next = new;
		new->prev = last;
	}
}
