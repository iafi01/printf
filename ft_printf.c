/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:43:00 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/13 14:35:31 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags ft_init_flags(void)
{
    t_flags flags;

    flags.width = 0;
    flags.type = 0;
    flags.precision = 0;
    flags.zero = 0;
    flags.dot = 0;
    flags.star = 0;
    flags.minus = 0;
    return (flags);
}

int ft_check_flags(const char *s, int i, t_flags *flags, va_list args)
{
    while (s[i] != '.' && !ft_is_type(s[i]))
    {
        if (!ft_isdigit(s[i]) && !ft_is_type(s[i]) && !ft_is_flags(s[i]))
            break;
        if (s[i] == '0' && flags->width == 0 && flags->minus == 0)
            flags->zero = 1;
        if (s[i] == '-')
            *flags = ft_flag_minus(*flags);
        if (s[i] == '*')
            flags->width = va_arg(args, int);
        if (ft_isdigit(s[i]))
            flags->width = (flags->width * 10) + (s[i] - '0');
        i++;
    }
    if (s[i] == '.')
        ft_flag_dot(s, ++i, *flags, args); //???
        //se flag dot é andato avanti non se ne accorge ft_is_type .7s é un esempio
        //perché ft_is_type leggerá 7  che nel ft_check fallisce e stampa tutto dopo il punto
        //anchee se metto ft_is_type flag->type dentro flag_dot in ft_check non saprá la i dov'era
    if (ft_is_type(s[i]))
        flags->type = s[i];
    return (i);
}

int ft_check(char *s, va_list args)
{
    int i;
    t_flags flags;
    int num;

    num = 0;
    i = 0;
    while (s[i])
    {
        flags = ft_init_flags();
        if (s[i] == '%' && s[i + 1])
        {
            i = ft_check_flags(s, ++i, &flags, args);
            if (ft_is_type(s[i]))
                num += ft_conversion(s[i], flags, args);
            else if (s[i])
                num += ft_putchar(s[i]);
        }
        else if (s[i] != '%')
            num += ft_putchar(s[i]);
        i++;
    }
    return (num);
}


int ft_printf(const char *str, ...)
{
    char *s;
    int num;
    va_list args;
    num = 0;
    s = ft_strdup(str);
    va_start(args, str);
    num += ft_check(s, args);
    va_end(args);
    free(s);
    return (num);
}