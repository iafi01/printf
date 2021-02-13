/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/13 11:06:15 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_string(char *str, t_flags flags)
{
    char *s;
    int len;

    s = ft_strdup(str);
    if (flags.precision != 0)
        ft_memmove(s, str, flags.precision);
    if (flags.precision == 0 && flags.dot == 1)
        return (0);
    len = ft_strlen(s);
    if (flags.minus == 1)
        ft_putstr(s);
    ft_width(flags.width, len, 0);
    if (flags.minus == 0)
        ft_putstr(s);
    return (len + flags.width);
}