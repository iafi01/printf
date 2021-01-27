/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:21:08 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/18 10:10:25 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;

	if (*little == '\0')
		return ((char *)big);
	len = ft_strlen(little);
	while (*big != '\0' && n-- >= len)
	{
		if (ft_strncmp(big, little, len) == 0)
			return ((char*)big);
		big++;
	}
	return (0);
}
