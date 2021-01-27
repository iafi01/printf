/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:29:46 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/19 11:51:48 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**copia da src a dest fino a len facendo attenzione alla
**sovrapposizione delle memorie che contengono src e dest
**da finire
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (((unsigned char *)dst > (unsigned char *)src))
	{
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
