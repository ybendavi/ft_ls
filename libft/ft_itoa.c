/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:49:44 by ybendavi          #+#    #+#             */
/*   Updated: 2021/09/16 19:59:09 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoalen(int n)
{
	long int	tmp;
	int			len;

	tmp = n;
	len = 0;
	if (tmp <= 0)
	{
		tmp = tmp * -1;
		len++;
	}
	while (tmp >= 1)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	tmp2;
	int			len;
	char		*str;

	tmp2 = n;
	len = ft_itoalen(tmp2);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!(str))
		return (NULL);
	if (tmp2 < 0)
	{
		tmp2 = tmp2 * -1;
		str[0] = '-';
	}
	str[len--] = 0;
	while (len >= 0 && str[len] == 0)
	{
		str[len--] = tmp2 % 10 + 48;
		tmp2 = tmp2 / 10;
	}
	return (str);
}
