/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:00 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/14 15:00:25 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_is_type(int c)
{
    if ((c == 'c') || (c == 's') || (c == 'i') || 
    (c == 'd') || (c == 'x') || (c == 'u') || (c == 'X'))
        return (1);
    return (0);
}

int     ft_is_flags(int c)
{
    return ((c == '0') || (c == '*') || (c == '.') || (c == '-'));
}

int ft_conversion(int c, t_flags flags, va_list args)
{
    int num;

    num = 0;
    if (c == 'c')
        num += ft_conversion_char(va_arg(args, int), flags);
    else if (c == 's')
        num += ft_conversion_string(va_arg(args, char*), flags);
    else if (c == 'p')
        num += ft_conversion_pointer(va_arg(args, unsigned long long), flags);
    else if (c == 'x')
        num += ft_conversion_hexa(va_arg(args, unsigned int), 0, flags);
    else if (c == 'X')
        num += ft_conversion_hexa(va_arg(args, unsigned int), 1, flags);
    else if (c == 'd' || c == 'i')
        num += ft_conversion_integer(va_arg(args, int), flags);
    else if (c == 'u')
        num += ft_conversion_unsigned(va_arg(args, unsigned int), flags);
    else if (c == '%')
        num += ft_conversion_percent(flags);
    return (num);
}
