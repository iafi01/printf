/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/18 08:51:57 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversion_char(int c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putchar(c);
	count += ft_width(flags.width, 1, 0);
	if (flags.minus == 0)
		count += ft_putchar(c);
	return (count);
}
