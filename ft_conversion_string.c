/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/15 16:02:59 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_string(char *str, t_flags flags)
{
    char *s;
    int len;

    if (str == NULL)
		str = ft_strdup("(null)");
    s = ft_strdup(str);
    if (flags.precision == 0)
        s = ft_strdup("");
    if (flags.precision > 0)
    {
        s = ft_strdup("");
        ft_memcpy(s, str, flags.precision);
    }
    len = ft_strlen(s);
    if (flags.minus == 1)
        ft_putstr(s);
    ft_width(flags.width, len, 0);
    if (flags.minus == 0)
        ft_putstr(s);
    return (len + flags.width);
}