/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:05:04 by ybendavi          #+#    #+#             */
/*   Updated: 2020/12/10 18:35:30 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	int				n;
	unsigned int	l_dst;
	unsigned int	l_src;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	i = 0;
	n = 0;
	while (dst[i] != '\0')
		i++;
	while (i < size - 1 && src[n] && size != 0)
	{
		dst[i] = src[n];
		i++;
		n++;
	}
	dst[i] = '\0';
	if (l_dst <= size)
		return (l_dst + l_src);
	else
		return (size + l_src);
}
