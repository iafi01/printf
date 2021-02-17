/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baseall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:46:04 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/17 13:27:13 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *ft_base(unsigned long long n, char *ret, int base, int count)
{
    while (n != 0)
    {
        if (n % base < 10)
            ret[count - 1] = (n % base) + '0';
        else
            ret[count - 1] = (n % base) + 55;
        n /= base;
        count--;
    }
    return (ret);
}

char *ft_baseall(unsigned long long n, int base, int up)
{
    char *ret;
    unsigned long long nb;
    int count;

    nb = n;
    count = 0;
    if (n == 0)
        return (ft_strdup("0"));
    while (n > 0)
    {
        n /= base;
        count++;
    }
    if (!(ret = malloc(sizeof(char) * ((count) + 1))))
        return (0);
    ret[count] = '\0';
    ret = ft_base(nb, ret, base, count);
    if (up == 0)
        ret = ft_lowercase(ret);
    return (ret);
}