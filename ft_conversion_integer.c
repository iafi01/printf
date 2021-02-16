/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/16 16:44:32 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_integer(int c, t_flags flags)
{
    int count;
    char *str;
    int len;
    int neg;
    int flag;
    
    flag = 0;
    neg = 0;
    count = 0;
    if (c < 0)
    {
        c *= -1;
        neg = -1;
    }
    str = ft_itoa(c);
    len = ft_strlen(str);
    if (flags.precision == 0 && c == 0)
    {
        str = ft_strdup("");
        count = ft_width(flags.width, 0, flags.zero);
        return (count);
    }
    if (flags.minus == 1)
    {
        if (neg < 0 && flag == 0)
        {
            ft_putchar('-');
            flag = 1;
        }
        count += ft_width(flags.precision, len, 1);
        ft_putstr(str);
    }
    if (flags.zero > 0)
    {
        if (flags.precision < len && flags.precision > 0)
            flags.zero = 0;
    }
    if (flags.precision > len)
    {
        if (flags.width <= flags.precision)
        {
            if (neg < 0 && flag == 0)
            {
                ft_putchar('-');
                flag = 1;
            }
        }
        count = ft_width(flags.width + neg, flags.precision, flags.width <= flags.precision );  
    }
    else if (flags.precision <= len)
    {
        if (flags.zero)
        {
            if (neg < 0 && flag == 0)
            {
                ft_putchar('-');
                flag = 1;
            }
        }
        count = ft_width(flags.width + neg, len + count, flags.zero);
    }
    if (flags.minus == 0)
    {
        if (neg < 0 && flag == 0)
            ft_putchar('-');
        ft_width(flags.precision, len, 1);
        ft_putstr(str);
    }
    return (count + len);
}