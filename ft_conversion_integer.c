/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/15 18:02:30 by liafigli         ###   ########.fr       */
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
        ft_putstr(str);
        ft_width(flags.precision, len, 1);
    }
    count = ft_width(flags.width, len, 0);
    if (flags.minus == 0)
    {
        ft_width(flags.precision, len, 1);
        ft_putstr(str);
    }
    return (count + len);
}

/*
int ft_putzero(int c)
{
    int i;
    char *str;

    str =NULL;
    i = 0;
    while (c /= 10)
    {
        str[i] = '0';
        i++;
    }
    ft_putstr(str);
    return (i);
}

int ft_conversion_integer(int c, t_flags flags)
{
    int count;
    char *str;
    int neg;

    if (c < 0)
    {
        neg = -1;
        c *= -1;
    }
    str = ft_itoa(c);
    count = 0;
    if (flags.minus == 1)
    {
        if (neg == -1)
            count += ft_putchar('-');
        count += ft_putzero(c);
        count += ft_putstr(str);
    }
    count = ft_width(flags.width, ft_strlen(str), 0);
    if (flags.minus == 0)
    {
        if (neg == -1)
            count += ft_putchar('-');
        count += ft_putzero(c);
        count += ft_putstr(str);
    }
    return (count);
}
*/