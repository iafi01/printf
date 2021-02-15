/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:53:53 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/15 13:54:31 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_width(int width, int leng, int zero)
{
    int ret;

    ret = 0;
    while (width - leng > 0)
    {
        if (zero)
            ft_putchar('0');
        else
            ft_putchar(' ');
        width--;
        ret++;
    }
    return (ret);
}
