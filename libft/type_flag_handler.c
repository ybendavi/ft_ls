/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_flag_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:06:20 by ybendavi          #+#    #+#             */
/*   Updated: 2021/04/28 11:45:58 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*type_flag_handler_p2(char flag, va_list arg, char *flags)
{
	char	*joined;
	char	*tmp;

	joined = NULL;
	if (flag == 'x')
		joined = flags_for_int(flags, ft_itoa_base(va_arg(arg, unsigned int),
					"0123456789abcdef"));
	else if (flag == 'X')
		joined = flags_for_int(flags, ft_itoa_base(va_arg(arg, unsigned int),
					"0123456789ABCDEF"));
	else if (flag == 'p')
	{
		tmp = ft_itoa_base((unsigned long long int)va_arg(arg, void *),
				"0123456789abcdef");
		joined = flags_for_p(flags, ft_strjoin("0x", tmp));
		free(tmp);
	}
	return (joined);
}

char	*type_flag_handler(char flag, va_list arg, char *flags)
{
	char	*joined;

	joined = NULL;
	if (flag == 's')
	{
		if ((joined = va_arg(arg, char *)))
			joined = flags_for_string(flags, ft_strdup(joined));
		else
			joined = flags_for_string(flags, ft_strdup("(null)"));
	}
	else if (flag == 'c')
		joined = flags_for_char(flags, va_arg(arg, int));
	else if (flag == '%')
		joined = flags_for_char(flags, '%');
	else if (flag == 'i' || flag == 'd')
		joined = flags_for_int(flags, ft_itoa(va_arg(arg, int)));
	else if (flag == '%')
		joined = ft_strdup("%");
	else if (flag == 'u')
		joined = flags_for_int(flags,
				ft_itoa_base(va_arg(arg, unsigned int), "0123456789"));
	else
		joined = type_flag_handler_p2(flag, arg, flags);
	return (joined);
}
