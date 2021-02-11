/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/11 11:46:37 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_string(char *str, t_flags flags, va_list args)
{
    char *s;
    int len;
    int width;

    s = NULL;
    width = flags.width;
    if (flags.dot == 0 && flags.precision != 0)
        len = ft_strlcpy(s, str, flags.precision);
    else
        len = ft_strlcpy(s, str, flags.precision);
    if (flags.minus == 1)
        ft_putstr(s);
    ft_width(width, len, 0);
    if (flags.minus == 0)
        ft_putstr(s);
    return (len + flags.width);
}