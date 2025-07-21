/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:25:02 by ybendavi          #+#    #+#             */
/*   Updated: 2021/09/16 20:02:25 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int	i;
	unsigned char		*s1;
	unsigned char		tmp;

	i = 0;
	tmp = c;
	s1 = (unsigned char *)s;
	while (i < n)
	{
		if (s1[i] == tmp || s1[i] == c)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
