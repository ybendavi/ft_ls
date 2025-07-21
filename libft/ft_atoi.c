/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:31:58 by ybendavi          #+#    #+#             */
/*   Updated: 2021/09/16 19:55:20 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	r;
	int	i;
	int	minus;

	i = 0;
	r = 0;
	minus = 0;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == ' ' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus++;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + nptr[i] - 48;
		i++;
	}
	if (minus != 0)
		return (r * -1);
	return (r);
}
