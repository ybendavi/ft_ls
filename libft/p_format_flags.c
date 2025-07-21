/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_format_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:29:23 by ybendavi          #+#    #+#             */
/*   Updated: 2021/04/28 19:48:18 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*p_zero(int width, char *str)
{
	char	*str2;
	int		i;
	int		n;

	i = width;
	n = ft_strlen(str);
	if (width <= n)
		return (str);
	str2 = (char*)ft_calloc(width + 1, sizeof(char));
	while (n > 1 && i > 1)
	{
		str2[i] = str[n--];
		i--;
	}
	while (i > 1)
		str2[i--] = '0';
	str2[1] = 'x';
	str2[0] = '0';
	free(str);
	return (str2);
}

char	*null_p(char *str)
{
	char	*tmp;

	tmp = ft_strnstr(str, "0x", ft_strlen(str));
	if (tmp[2] == '0')
	{
		if (str[0] == ' ')
			tmp = &tmp[1];
		str = ft_memset(str, ' ', ft_strlen(str));
	}
	tmp = ft_memset(tmp, '0', 2);
	return (tmp);
}

char	*mem_setter(char *str, char *tmp, int width, int size)
{
	if (str[0] != ' ')
	{
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	else
		tmp = ft_memcpy(tmp, "0x", 2);
	if (width == 0 && size > 2 && str[size - 1] == ' ')
		str[2] = 0;
	return (str);
}

char	*p_point(int width, char *str, char flag, int s)
{
	int		size;
	int		i;
	char	*tmp;

	size = ft_strlen(str);
	tmp = null_p(str);
	i = width;
	if (width < size && str && width != 0)
		str = inferior_width(i, str, flag, size);
	if (width > size && str && width != 0)
		str = superior_width(i, str, flag, size);
	i = 0;
	while (str[i] == ' ' || str[i] == '0')
		i++;
	if (str[i] == 0 && width == 0)
		ft_strchr(str, '0')[0] = s == 0 ? 0 : ' ';
	i = 0;
	if (width == size)
		str = equal_width(str, size);
	return (mem_setter(str, tmp, width, (int)ft_strlen(str)));
}
