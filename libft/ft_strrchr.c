/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <ybendavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:35:47 by ybendavi          #+#    #+#             */
/*   Updated: 2021/09/16 20:25:19 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			s1 = (char *)&s[i];
		i++;
	}
	if (s[i] == (unsigned char)c)
		s1 = (char *)&s[i];
	return (s1);
}
