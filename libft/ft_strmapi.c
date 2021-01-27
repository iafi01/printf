/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:15:32 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/17 15:07:53 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	str = ft_strdup(s);
	if (!f || !str)
		return (0);
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
