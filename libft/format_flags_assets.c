/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags_assets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:11:01 by ybendavi          #+#    #+#             */
/*   Updated: 2021/04/22 20:56:22 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*check_flags(const char *format)
{
	int	i;

	i = 1;
	while (format[i] && (format[i] == '-' || format[i] == '0'))
		i++;
	if (format[i] == '*')
	{
		i++;
		if (ft_strchr("cspdixXu%", format[i]) == NULL && format[i] != '.')
			return (&format[i]);
	}
	while (format[i] && ft_isdigit(format[i]) != 0)
		i++;
	if (format[i] == '.')
		i = check_flags_assets(format, i);
	if (ft_strchr("cspdiuxX%", format[i]) == NULL || format[i] == 0)
		return (&format[i]);
	else
		return (&format[i + 1]);
}

int			width_size(char *flags)
{
	char	s_size[ft_strlen(flags) + 1];
	int		i;

	i = 0;
	while (flags[i] && ft_isalnum(flags[i]))
	{
		s_size[i] = flags[i];
		i++;
	}
	s_size[i] = 0;
	return (ft_atoi(s_size));
}

char		*zero(int width, char *str)
{
	char	*str2;
	int		i;
	int		n;

	i = width;
	n = ft_strlen(str);
	if (width <= n)
		return (str);
	str2 = (char *)ft_calloc(width + 1, sizeof(char));
	while (n >= 0 && i >= 0)
	{
		str2[i] = str[n--];
		i--;
		if (n >= 0 && str[n] == '-')
		{
			str2[0] = '-';
			n--;
		}
	}
	while (i >= 0 && str2[i] == 0)
		str2[i--] = '0';
	free(str);
	return (str2);
}

char		*digit(int width, char *str)
{
	char	*str2;
	int		i;
	int		n;

	i = width;
	n = ft_strlen(str);
	if (width <= n)
		return (str);
	str2 = (char *)ft_calloc(width + 1, sizeof(char));
	while (n >= 0)
	{
		str2[i] = str[n];
		i--;
		n--;
	}
	while (i >= 0)
	{
		str2[i] = ' ';
		i--;
	}
	free(str);
	return (str2);
}

char		*minus(int width, char *str)
{
	char	*str2;
	int		i;

	i = 0;
	if (width <= (int)ft_strlen(str))
		return (str);
	str2 = (char *)ft_calloc(width + 1, sizeof(char));
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	while (i < width)
	{
		str2[i] = ' ';
		i++;
	}
	free(str);
	return (str2);
}
