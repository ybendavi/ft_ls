/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:23:55 by ybendavi          #+#    #+#             */
/*   Updated: 2021/09/16 19:56:36 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	tab = malloc(nmemb * size);
	if (!(tab))
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
