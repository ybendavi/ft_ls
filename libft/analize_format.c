/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:51:21 by ybendavi          #+#    #+#             */
/*   Updated: 2021/04/23 10:42:40 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_printer(const char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	if (i > 0)
		write(1, format, i);
	return (i);
}

int		str_printer(char *tmp, int count, va_list arg)
{
	char	tmp2;
	char	*str3;

	tmp2 = tmp[count - 1];
	tmp[count - 1] = 0;
	str3 = type_flag_handler(tmp2, arg, &tmp[1]);
	if (tmp2 == 'c' || tmp2 == '%')
	{
		count = calc_width(&tmp[1]);
		write(1, str3, count);
	}
	else
	{
		count = ft_strlen(str3);
		ft_putstr_fd(str3, 1);
	}
	if (str3)
		free(str3);
	return (count);
}

int		arg_printer(const char *format, va_list arg)
{
	char	*tmp;
	int		count;

	tmp = set_flags(format, arg);
	count = ft_strlen(tmp);
	if (ft_strchr("cspiudxX%", tmp[count - 1]) == NULL)
		ft_putstr_fd(tmp, 1);
	else
		count = str_printer(tmp, count, arg);
	free(tmp);
	return (count);
}

int		analize_format(const char *format, va_list arg)
{
	int	i;
	int	count;
	int	n;

	i = 0;
	count = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			count = count + arg_printer(&format[i], arg);
			format = check_flags(&format[i]);
			i = 0;
		}
		if (format[i])
		{
			n = format_printer(&format[i]);
			count = count + n;
			i = i + n;
		}
	}
	return (count);
}
