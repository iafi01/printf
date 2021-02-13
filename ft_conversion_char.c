/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/13 11:47:43 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_conversion_char(int c, t_flags flags)
{
    int ret;

    ret = 0;
    if (flags.minus == 1)
        ft_putchar(c);
    ft_width(flags.width, 1, 0);
    if (flags.minus == 0)
        ft_putchar(c);  
    return (ret + 1);
}