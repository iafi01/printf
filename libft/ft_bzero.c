/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:03:58 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/11 11:32:15 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**chiamo memset utilizzando lo zero della ascii come secondo parametro
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
