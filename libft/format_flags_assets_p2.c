/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags_assets_p2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:48:21 by ybendavi          #+#    #+#             */
/*   Updated: 2021/04/28 11:45:07 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*star_flag(va_list arg, char *flags, int n)
{
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_itoa(va_arg(arg, int));
	while (tmp2[i])
	{
		flags[n] = tmp2[i];
		i++;
		n++;
	}
	free(tmp2);
	return (flags);
}

int		check_flags_assets(const char *format, int i)
{
	i++;
	if (format[i] == '*' && format[i])
		i++;
	else
	{
		while (ft_isdigit(format[i]) != 0 && format[i])
			i++;
	}
	return (i);
}

int		calc_width(char *flags)
{
	int	i;
	int	width;

	i = 0;
	width = 1;
	while (flags[i] == '-' || flags[i] == '0')
		i++;
	width = ft_isalnum(flags[i]) != 0 ? width_size(&flags[i]) : 1;
	return (width);
}
