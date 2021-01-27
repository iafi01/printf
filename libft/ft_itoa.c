/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:05:09 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/18 18:06:37 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
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

char			*ft_itoa(int n)
{
	size_t		i;
	char		*str;
	int			sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
