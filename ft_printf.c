/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:43:00 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/04 14:35:27 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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

int ft_check(char *s, va_list args)
{
    int i;
    t_flags *flags;
    int num;

    num = 0;
    *flags = ft_init_flags();
    i = 0;
    while (s[i])
    {
        if (s[i] == '%' && !(s[i + 1]))
            if (s[i] == '0')
                flags->zero = 1;
            else if (s[i] == '-')
                flags->minus = 1;
        i++;
    }
    return (0);
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
