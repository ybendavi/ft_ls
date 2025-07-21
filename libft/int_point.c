/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:24:46 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 21:19:12 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_fuller(char *str, int width, char flag, int i)
{
	if (width <= i)
		return (str);
	while (width != i && width > 0 && i >= 0 &&
			(ft_isalnum(str[i]) != 0
			|| str[i] == '-') && flag == '-')
		str[--width] = str[i--];
	while (width != i && --width >= 0 && flag == '-')
		str[width] = '0';
	if (ft_strchr(str, '-') != NULL && flag == '-')
	{
		ft_strchr(str, '-')[0] = '0';
		str[0] = '-';
	}
	return (str);
}

char	*inferior_width(int width, char *str, char flag, int size)
{
	int	i;
	int	b;

	i = 0;
	b = 3;
	while (str[i] && (ft_isalnum(str[i]) == 0 || str[i] == 0) && flag == '1')
		i++;
	if (i > 0 && str[i - 1] == '-' && flag == '1')
		b = 0;
	if (i > 0 && flag == '1' && str[i - 1] != '-' &&
			ft_isalnum(str[size - width]) == 0)
		b = 1;
	while (--i > size - width && flag == '1' && i >= 0)
		str[i] = '0';
	if (flag == '1' && b == 0)
		str[i] = '-';
	if (flag == '1' && b == 1)
		str[i] = '0';
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) != 0 || str[i] == '-') && flag == '-')
		i++;
	i--;
	str = str_fuller(str, width, flag, i);
	return (str);
}

char	*superior_width(int width, char *str, char flag, int size)
{
	char	*tmp;
	int		i;

	tmp = (char *)calloc(sizeof(char), (width + 2));
	while (--size >= 0 && ft_isalnum(str[size]) != 0 && flag == '1')
		tmp[--width] = str[size];
	if (size >= 0 && str[size] == '-' && flag == '1')
		tmp[0] = '-';
	while (flag == '1' && --width >= 0 && tmp[width] == 0)
		tmp[width] = '0';
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) != 0 || str[i] == '-') && flag == '-')
		i++;
	while (--i >= 0 && (ft_isalnum(str[i]) != 0 || str[i] == '-') &&
			flag == '-')
		tmp[--width] = str[i];
	while (flag == '-' && --width >= 0)
		tmp[width] = '0';
	if (ft_strchr(tmp, '-') != NULL)
	{
		ft_strchr(tmp, '-')[0] = '0';
		tmp[0] = '-';
	}
	free(str);
	return (tmp);
}

char	*equal_width(char *str, int size)
{
	int		i;
	char	tmp2[ft_strlen(str)];

	i = 0;
	ft_memset(tmp2, '0', size);
	tmp2[size] = 0;
	while (str[i] && ft_isalnum(str[i]) == 0)
		i++;
	while (ft_isalnum(str[i]) != 0)
		i++;
	while (i > 0 && size > 0 && ft_isalnum(str[--i]) != 0)
	{
		tmp2[--size] = str[i];
	}
	tmp2[ft_strlen(str)] = 0;
	i = 0;
	while (tmp2[i])
	{
		str[i] = tmp2[i];
		i++;
	}
	return (str);
}

char	*point(int width, char *str, char flag, int s)
{
	int	size;
	int	i;

	size = ft_strlen(str);
	if (width < size && str && width != 0)
	{
		i = ft_strchr(str, '-') != NULL ? width + 1 : width;
		str = inferior_width(i, str, flag, size);
	}
	if ((width > size ||
			(width == size &&
				ft_strchr(str, '-') != NULL)) && str && width != 0)
	{
		i = ft_strchr(str, '-') != NULL ? width + 1 : width;
		str = superior_width(i, str, flag, size);
	}
	i = 0;
	while (str[i] == '0' || str[i] == ' ')
		i++;
	if (str[i] == 0 && width == 0)
		ft_strchr(str, '0')[0] = s == 0 ? 0 : ' ';
	i = 0;
	if (width == size && ft_strchr(str, '-') == NULL)
		str = equal_width(str, size);
	return (str);
}
