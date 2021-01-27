/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:10:09 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/17 10:51:29 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**copia da s2 a s1 fino a len o fino a quando non trova c
*/

void	*ft_memccpy(void *s1, const void *s2, int c, size_t len)
{
	size_t i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i < len)
	{
		((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
		if ((unsigned char)c == ((unsigned char *)s2)[i])
			return (s1 + 1 + i);
		i++;
	}
	return (0);
}
