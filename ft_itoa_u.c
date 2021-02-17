/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:05:09 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/17 17:21:05 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count(unsigned int n)
{
	size_t d;

	d = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char			*ft_itoa_u(unsigned int n)
{
	size_t		i;
	char		*str;
	int			sign;

	if (n == 4294967295)
		return (ft_strdup("4294967295"));
	sign = (n < 0) ? 1 : 0;
	n = (sign == 1) ? n * -1 : n;
	i = ft_count(n);
	if (!(str = (char *)malloc(i + sign + 1)))
		return (0);
	str[i + sign] = '\0';
	while (i > 0)
	{
		str[--i + sign] = n % 10 + '0';
		n /= 10;
	}
	str[0] = (sign == 1) ? '-' : str[0];
	return (str);
}
