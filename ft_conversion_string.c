/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/07 15:23:18 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_string(char *str, t_flags flags)
{
    char *s;
    int len;
    int width;

    width = flags.width;
    if (flags.minus == 1)
        ft_putstr(s);
    s = ft_strlcpy(s, str, flags.precision);
    len = ft_strlen(s);
    while (width - len > 0)
    {
        ft_putchar(' ');
        width--;
    }
    if (flags.minus == 0)
        ft_putstr(s);
    return (len + flags.width);
}