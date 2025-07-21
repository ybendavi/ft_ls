/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:11:44 by ybendavi          #+#    #+#             */
/*   Updated: 2021/04/28 15:41:52 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*flags_for_int(char *flags, char *str)
{
	int		i;
	int		width;
	char	flag;

	i = 0;
	flag = '1';
	while (flags[i] == '-' || flags[i] == '0')
	{
		flag = flags[i] == '-' ? '-' : flag;
		if (flags[i] == '0' && flag != '-' &&
			(ft_strchr(flags, '.') == NULL || ft_strchr(flags, '-') != NULL))
			flag = '0';
		i++;
	}
	width = ft_isalnum(flags[i]) != 0 ? width_size(&flags[i]) : 0;
	str = flag == '-' ? minus(width, str) : str;
	str = flag == '1' ? digit(width, str) : str;
	str = flag == '0' ? zero(width, str) : str;
	while (i < (int)ft_strlen(flags) && i >= 0 && flags[i])
	{
		if (flags[i] == '.' && flags[i + 1] != '-')
			str = point(width_size(&flags[++i]), str, flag, width);
		i++;
	}
	return (str);
}

char	*flags_for_char(char *flags, char c)
{
	char	*str;
	int		i;
	int		width;
	char	flag;

	str = NULL;
	i = 0;
	flag = '1';
	while (flags[i] == '-' || flags[i] == '0')
	{
		flag = flags[i] == '-' ? '-' : flag;
		if (flags[i] == '0' && flag != '-' &&
			(ft_strchr(flags, '.') == NULL || ft_strchr(flags, '-') != NULL))
			flag = '0';
		i++;
	}
	width = ft_isalnum(flags[i]) != 0 ? width_size(&flags[i]) : 1;
	str = flag == '-' ? minus(width, ft_strdup("")) : str;
	str = flag == '1' ? digit(width, ft_strdup("")) : str;
	str = flag == '0' ? zero(width, ft_strdup("")) : str;
	str[0] = flag == '-' ? c : str[0];
	if (flag == '1' || flag == '0')
		str[width - 1] = c;
	return (str);
}

char	*point_str(char *flags, char *str)
{
	int	i;
	int	width;

	i = 0;
	while (flags[i] && flags[i] != '.')
		i++;
	if (flags[i] == '.')
	{
		if (flags[i + 1] == '-')
			return (str);
		width = width_size(&flags[i + 1]);
		i = 0;
		while (i < width && str[i])
			i++;
		while (str[i])
		{
			str[i] = 0;
			i++;
		}
	}
	return (str);
}

char	*flags_for_string(char *flags, char *str)
{
	int		i;
	int		width;
	int		size;
	char	flag;

	i = 0;
	flag = '1';
	str = point_str(flags, str);
	size = (int)ft_strlen(str);
	while (flags[i] == '-' || flags[i] == '0')
	{
		flag = flags[i] == '-' ? '-' : flag;
		if (flags[i] == '0' && flag != '-' &&
			(ft_strchr(flags, '.') == NULL || ft_strchr(flags, '-') != NULL))
			flag = '0';
		i++;
	}
	width = ft_isalnum(flags[i]) != 0 ? width_size(&flags[i]) : size;
	str = flag == '-' ? minus_str(str, width) : str;
	str = flag == '1' ? digit_str(str, width) : str;
	str = flag == '0' ? zero_str(str, width) : str;
	return (str);
}

char	*flags_for_p(char *flags, char *str)
{
	int		i;
	int		width;
	char	flag;

	i = 0;
	flag = '1';
	while (flags[i] == '-' || flags[i] == '0')
	{
		flag = flags[i] == '-' ? '-' : flag;
		if (flags[i] == '0' && flag != '-' &&
			(ft_strchr(flags, '.') == NULL || ft_strchr(flags, '-') != NULL))
			flag = '0';
		i++;
	}
	width = ft_isalnum(flags[i]) != 0 ? width_size(&flags[i]) : 0;
	str = flag == '-' ? minus(width, str) : str;
	str = flag == '1' ? digit(width, str) : str;
	str = flag == '0' ? p_zero(width, str) : str;
	while (i < (int)ft_strlen(flags) && i >= 0 && flags[i])
	{
		if (flags[i] == '.' && flags[i + 1] != '-')
			str = p_point(width_size(&flags[++i]), str, flag, width);
		i++;
	}
	return (str);
}
