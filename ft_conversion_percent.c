/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_percent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/07 15:30:59 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_percent(t_flags flags)
{
    int width;

    width = flags.width;
    if (flags.minus == 1)
        ft_putchar('%');
    while (width - 1 > 0)
    {
        ft_putchar(' ');
        width--;
    }
    if (flags.minus == 0)
        ft_putchar('%');
    return (1 + flags.width);
}