/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:29:15 by ybendavi          #+#    #+#             */
/*   Updated: 2021/10/19 13:29:21 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (*alst == NULL && new != NULL)
	{
		*alst = new;
		new->next = NULL;
	}
	else if (*alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
