/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/13 17:16:57 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_integer(int c, t_flags flags)
{
    int count;
    char *str;
    int len;

    str = ft_itoa(c);
    len = ft_strlen(str);
    count = 0;
    if (flags.minus == 1)
    {
        while (flags.precision - len > 0)
        {
            ft_putchar('0');
            len++;
        }
        ft_putstr(str);
    }
    count = ft_width(flags.width, len, 0);
    if (flags.minus == 0)
    {
        while (flags.precision - len > 0)
        {
            ft_putchar('0');
            len++;
        }
        ft_putstr(str);
    }
    return (count + len);
}