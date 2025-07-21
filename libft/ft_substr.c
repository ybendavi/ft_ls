/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:05:10 by ybendavi          #+#    #+#             */
/*   Updated: 2021/09/16 20:23:48 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	substrlen(char const *s, unsigned int start, size_t len)
{
	if (len > ft_strlen(&s[start]))
		return (ft_strlen(&s[start]));
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
	{
		dest = (char *)ft_calloc(sizeof(char), 1);
		if (!(dest))
			return (NULL);
		return (dest);
	}
	i = substrlen(s, start, len);
	dest = (char *)ft_calloc(sizeof(char), i + 1);
	if (!(dest))
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	return (dest);
}
