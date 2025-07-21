/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_format_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:16:34 by ybendavi          #+#    #+#             */
/*   Updated: 2021/04/23 14:32:49 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*minus_str(char *str, int width)
{
	char	*tmp;
	int		len;

	tmp = NULL;
	len = ft_strlen(str);
	if (width > len)
	{
		tmp = str;
		if (!(str = ft_calloc(sizeof(char), width + 1)))
			return (NULL);
		str = (char *)ft_memset(str, ' ', width);
		str = (char *)ft_memcpy(str, tmp, len);
		free(tmp);
	}
	return (str);
}

char	*digit_str(char *str, int width)
{
	char	*tmp;
	int		len;

	tmp = NULL;
	len = ft_strlen(str);
	if (width > len)
	{
		tmp = str;
		if (!(str = ft_calloc(sizeof(char), width + 1)))
			return (NULL);
		str = (char *)ft_memset(str, ' ', width);
		len--;
		width--;
		while (len >= 0)
		{
			str[width] = tmp[len];
			width--;
			len--;
		}
		free(tmp);
	}
	return (str);
}

char	*zero_str(char *str, int width)
{
	char	*tmp;
	int		len;

	tmp = NULL;
	len = ft_strlen(str);
	if (width > len)
	{
		tmp = str;
		if (!(str = ft_calloc(sizeof(char), width + 1)))
			return (NULL);
		str = (char *)ft_memset(str, '0', width);
		len--;
		width--;
		while (len >= 0)
		{
			str[width] = tmp[len];
			width--;
			len--;
		}
		free(tmp);
	}
	return (str);
}
