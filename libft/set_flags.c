/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:55:22 by ybendavi          #+#    #+#             */
/*   Updated: 2021/04/23 11:00:32 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*set_minus_o_zero(const char *format, char *list)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
		{
			list[count] = '-';
			break ;
		}
		if (format[i] == '0')
			list[count] = '0';
		i++;
	}
	if (list[count] != 0)
		count++;
	return (&list[count]);
}

const char	*set_point(const char *format, char *list, va_list arg)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	list[count] = format[i];
	count++;
	i++;
	if (format[i] == '*')
	{
		list = star_flag(arg, list, count);
		count = (int)ft_strlen(list);
		i++;
	}
	else
	{
		while (ft_isdigit(format[i]) != 0)
		{
			list[count] = format[i++];
			count++;
		}
	}
	return (&format[i]);
}

char		*end_listing(const char *format, char *list, va_list arg, int count)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]) != 0)
	{
		list[count] = format[i];
		count++;
		i++;
	}
	if (format[i] == '.')
	{
		format = set_point(&format[i], &list[count], arg);
		i = 0;
	}
	count = ft_strlen(list);
	if (ft_strchr("cspdiudxX%", format[i]) != NULL)
		list[count] = format[i];
	return (list);
}

char		*set_flags(const char *format, va_list arg)
{
	char	*list;
	char	*flags;

	if (!(flags = ft_calloc(sizeof(char), ft_strlen(format) + 20)))
		return (NULL);
	list = flags;
	if (*format == '%')
	{
		*list++ = '%';
		if (*++format == '%')
			return (flags);
	}
	list = set_minus_o_zero(format, list);
	while (*format == '-' || *format == '0')
		format++;
	if (*format == '*')
	{
		list = star_flag(arg, list, (int)ft_strlen(list));
		if (*++format != '.' && ft_strchr("cspiudxX%", *format) == NULL)
			return (flags);
	}
	list = end_listing(format, list, arg, (int)ft_strlen(list));
	return (flags);
}
