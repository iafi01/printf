/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:26:06 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/12 16:55:51 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags ft_flag_minus(t_flags flags)
{
    flags.minus = 1;
    flags.zero = 0;
    return (flags);
}

t_flags ft_flag_dot(const char *s, int i, t_flags flags, va_list args)
{
    flags.dot = 1;
    while (!ft_is_type(s[i]))
    {
        if (s[i] == '*')
            flags.precision = va_arg(args, int);
        if (ft_isdigit(s[i]))
            flags.precision = s[i];
        i++;
    }
    return (flags);
}