/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/11 11:51:57 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_char(int c, t_flags flags, va_list args)
{
    int ret;
    int i;

    ret = 0;
    i = flags.width - 1;
    if (flags.minus == 0)
    {
        while (i)
        {
            ft_putchar(' ');
            i--;
        }
        ft_putchar(c);
    }
    else
    {
        ft_putchar(c);
        while (i)
        {
            ft_putchar(' ');
            i--;
        }
    }
    return (ret + 1);
}