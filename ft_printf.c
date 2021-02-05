/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:43:00 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/05 16:50:54 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags ft_init_flags(void)
{
    t_flags flags;

    flags.width = 0;
    flags.type = 0;
    flags.zero = 0;
    flags.dot = -1;
    flags.star = 0;
    flags.minus = 0;
    return (flags);
}

int ft_check_flag(const char *s, int i, t_flags *flags, va_list args)
{
    while (s[i])
    {
        if (!ft_isdigit(s[i]) && !ft_is_type(s[i]) && !ft_is_flags(s[i]))
            break;
        
    }
}

int ft_check(char *s, va_list args)
{
    int i;
    t_flags *flags;
    int num;

    num = 0;
    i = 0;
    while (s[i])
    {
        *flags = ft_init_flags();
        if (s[i] == '%' && s[i + 1])
        {
            //check flags before
            if (ft_is_type(s[i]))
                num += ft_convert();
            
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
