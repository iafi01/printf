/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:58:06 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/09 12:00:05 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char			*ft_u_itoa(unsigned int n)
{
	size_t		i;
	char		*str;

	i = ft_count(n);
	if (!(str = (char *)malloc(i + 1)))
		return (0);
	str[i] = '\0';
	while (i > 0)
	{
		str[--i] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
