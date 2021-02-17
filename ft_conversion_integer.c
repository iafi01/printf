/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/17 09:50:16 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int ft_init_int(void)
{
    t_int i;

    i.neg = 0;
    i.flag = 0;
    i.count = 0;
    i.len = 0;
    return (i);
}

int ft_conversion_integer(int c, t_flags flags)
{
    t_int i;
    i = ft_init_int();
    char *str;
    
    
    if (c < 0)
    {
        c *= -1;
        i.neg = -1;
    }
    str = ft_itoa(c);
    i.len = ft_strlen(str);
    if (flags.precision == 0 && c == 0)
    {
        str = ft_strdup("");
        return(ft_width(flags.width, 0, flags.zero));
    }
    if (flags.minus == 1)
    {
        if (i.neg < 0)
        {
            ft_putchar('-');
            i.flag = 1;
        }
        i.count += ft_width(flags.precision, i.len, 1);
        ft_putstr(str);
    }
    if (flags.zero > 0)
        if (flags.precision < i.len && flags.precision > 0)
            flags.zero = 0;
    if (flags.precision > i.len)
    {
            if (i.neg < 0 && i.flag == 0 && flags.width <= flags.precision)
            {
                ft_putchar('-');
                i.flag = 1;
            }
        i.count = ft_width(flags.width + i.neg, flags.precision, flags.width <= flags.precision );  
    }
    else if (flags.precision <= i.len)
    {
        if (flags.zero)
            if (i.neg < 0 && i.flag == 0)
            {
                ft_putchar('-');
                i.flag = 1;
            }
        i.count = ft_width(flags.width + i.neg, i.len + i.count, flags.zero);
    }
    if (flags.minus == 0)
    {
        if (i.neg < 0 && i.flag == 0)
            ft_putchar('-');
        ft_width(flags.precision, i.len, 1);
        ft_putstr(str);
    }
    return (i.count + i.len);
}