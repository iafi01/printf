/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/09 14:57:00 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_pointer(unsigned long long c, t_flags flags)
{
    char *pointer;
    char count;
    int len;

    pointer = ft_baseall(c, 16, 0);
    len = ft_strlen(pointer);
    if (flags.minus == 1)
        ft_putstr(pointer);
    count = ft_width(flags.width, len, 0);
    if (flags.minus == 0)
        ft_putstr(pointer);
    return (count + len);
}