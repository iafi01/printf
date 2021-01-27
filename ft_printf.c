/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:43:00 by liafigli          #+#    #+#             */
/*   Updated: 2021/01/25 11:26:54 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void    flag(char c)
{
    
    if (c == 'd')
        ft_putnbr_fd(va_arg( ::::, int), 1);
    if (c == 'c')
        ft_putnbr_fd(va_arg( ::::, char), 1);
    if (c == 's')
        ft_putnbr_fd(va_arg( ::::, char*), 1);
    if (c == 'u')
        ft_putnbr_fd(va_arg( ::::, unsigned int), 1);
    if (c == 'i')
        ft_putnbr_fd(va_arg( ::::, int), 1);
    if (c == 'x')
        ft_putnbr_fd(va_arg( ::::, int), 1);
    if (c == 'X')
        ft_putnbr_fd(va_arg( ::::, int), 1);
    if (c == 'p')
        ft_putnbr_fd(va_arg( ::::, void *), 1);
}

int ft_printf(const char *fix, ...)
{
    va_list ap;

    va_start(ap, fix);
    while (*fix)
    {
        if (*fix++ == '%')
        {
            if (*fix == '%')
                ft_putchar_fd('%', 1);
            else
                flag(*fix);
        }
        else
            ft_putchar_fd(*fix, 1);
        *fix++;
    }
    va_end(ap);
}
