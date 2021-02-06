/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/06 14:51:41 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_char(int c, t_flags flags)
{
    int ret;
    int i;

    ret = 0;
    i = 0;
    ft_putchar(c);
    if (flags.minus == 1)
    {
        i = flags.width;
        while (i)
        {
            ft_putchar(' ');
            i--;
        }
    }
    return (ret + 1);
}