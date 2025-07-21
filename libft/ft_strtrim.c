/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:41:33 by ybendavi          #+#    #+#             */
/*   Updated: 2021/09/16 20:25:49 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlenminusset(char const *s1, char const *set, int i)
{
	int	len;
	int	y;

	len = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	while (s1[i])
	{
		y = i;
		while (ft_strchr(set, s1[i]) != NULL && s1[i])
		{
			i++;
			if (y != 0)
				len++;
		}
		if (s1[i] == '\0' && y != 0)
			len = len - (i - y);
		if (s1[i])
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	len = ft_strlenminusset(s1, set, i);
	j = 0;
	str = (char *)calloc(sizeof(char), len + 1);
	if (!(str))
		return (NULL);
	while (j < len)
	{
		while (ft_strchr(set, s1[i]) != NULL && s1[i])
			i++;
		while (j < len)
		{
			str[j] = s1[i];
			j++;
			i++;
		}
	}
	return (str);
}
