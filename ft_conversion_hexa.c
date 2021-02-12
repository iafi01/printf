/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/11 13:02:06 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//teoricamente gestisce lo zero e la width attraverso la ft_width, il meno attraverso i due if e le low/capital letter con ft_baseall(cap)
int ft_conversion_hexa(unsigned int c, int cap, t_flags flags)
{
    int len;
    char *hexa;
    int ret;
    char *tmp;

    hexa = ft_baseall(c, 16, cap);
    tmp = ft_strdup("0x");
    hexa = ft_strjoin(tmp, hexa);
    free(tmp);
    len = ft_strlen(hexa);
    if (flags.minus == 1)
        ft_putstr(hexa);
    ret = ft_width(flags.width, len, flags.zero);
    if (flags.minus == 0)
        ft_putstr(hexa);
    return (ret + 2);
}