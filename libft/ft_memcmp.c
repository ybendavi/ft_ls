/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:49:38 by ybendavi          #+#    #+#             */
/*   Updated: 2020/12/18 16:37:03 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s12;
	unsigned char	*s22;

	i = 0;
	s12 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (i < n && n != 0)
	{
		if (s12[i] != s22[i])
			return (s12[i] - s22[i]);
		i++;
	}
	return (0);
}
