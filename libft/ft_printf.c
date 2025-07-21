/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:32:47 by ybendavi          #+#    #+#             */
/*   Updated: 2021/04/21 16:16:23 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*c_to_str(int c)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = 0;
	return (str);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, format);
	count = analize_format(format, arg);
	va_end(arg);
	return (count);
}
