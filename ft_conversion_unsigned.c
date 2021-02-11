/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/11 11:49:46 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_unsigned(int c, t_flags flags, va_list args)
{
    int count;
    char *str;
    int len;
    //use itoa and convert it for spaces
    str = ft_u_itoa(c);
    len = ft_strlen(str);
    count = 0;
    if (flags.minus == 1)
        ft_putstr(str);
    while (flags.width - len > 0)
    {
        ft_putchar(' ');
        flags.width--;
        count++;
    }
    if (flags.minus == 0)
        ft_putstr(str);
    return (count + len);
}