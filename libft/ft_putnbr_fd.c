/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:06:35 by ybendavi          #+#    #+#             */
/*   Updated: 2020/12/21 12:32:59 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	tmp;
	long int	div;
	long int	tmp2;

	tmp = n;
	div = 1;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		write(fd, "-", 1);
	}
	tmp2 = tmp;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		div = div * 10;
	}
	tmp = tmp2;
	while (div >= 1)
	{
		n = tmp / div + 48;
		write(fd, &n, 1);
		tmp = tmp % div;
		div = div / 10;
	}
}
