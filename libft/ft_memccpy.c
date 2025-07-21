/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:55:49 by ybendavi          #+#    #+#             */
/*   Updated: 2021/09/16 20:00:01 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	unsigned const char	*src1;

	i = 0;
	dest1 = (unsigned char *)dest;
	src1 = (unsigned const char *)src;
	while (i < n && src1[i] != (unsigned char)c)
	{
		dest1[i] = src1[i];
		i++;
	}
	if (src1[i] == (unsigned char)c && i < n)
	{
		dest1[i] = (unsigned char)c;
		return (dest + i + 1);
	}
	else
		return (NULL);
}
