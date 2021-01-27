/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:52:24 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/17 12:45:15 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*s)
		s++;
	if ((char)c == 0)
		return ((char *)s);
	while (s >= str)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
