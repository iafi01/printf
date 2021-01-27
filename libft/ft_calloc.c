/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:03:04 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/15 19:25:31 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *a;

	a = malloc(count * size);
	if (a == NULL)
		return (NULL);
	else
	{
		ft_memset(a, 0, size * count);
		return (a);
	}
}
