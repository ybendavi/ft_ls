/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:17:20 by ybendavi          #+#    #+#             */
/*   Updated: 2021/10/19 13:59:03 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*mem_overlap(unsigned char *dest, unsigned const char *src, int n)
{
	char			tmp[dest - src];
	int				i;
	int				y;
	unsigned char	c;

	i = 0;
	ft_memcpy(tmp, &dest[i], dest - src);
	ft_memcpy(dest, src, dest - src);
	n = n - (dest - src);
	while (n > 0)
	{
		i = i + (dest - src);
		y = 0;
		while (y < dest - src && n > 0)
		{
			c = dest[i + y];
			dest[i + y] = tmp[y];
			tmp[y] = c;
			y++;
			n--;
		}
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				size;

	size = n;
	if (dest == src || n == 0)
		return (dest);
	if (src < dest && dest - src < size && dest - src > 0)
	{
		return (mem_overlap(dest, src, size));
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
