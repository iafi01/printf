/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/18 19:09:34 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_int		ft_init_int(void)
{
	t_int i;

	i.neg = 0;
	i.flag = 0;
	i.count = 0;
	i.len = 0;
	return (i);
}

static int	ft_first(t_flags flags, t_int *i, char *str)
{
	int c;

	c = 0;
	if (flags.minus == 1)
	{
		if (i->neg < 0 && i->flag == 0)
		{
			c += ft_putchar('-');
			i->flag = 1;
		}
		i->count += ft_width(flags.precision, i->len, 1);
		c += ft_putstr(str);
	}
	return (c);
}

static int	ft_second(t_flags flags, t_int *i)
{
	int c;

	c = 0;
	if (flags.precision > i->len)
	{
		if (i->neg < 0 && i->flag == 0 && flags.width <= flags.precision)
		{
			c += ft_putchar('-');
			i->flag = 1;
		}
		i->count += ft_width(flags.width + i->neg, flags.precision,
		flags.width <= flags.precision);
	}
	else if (flags.precision <= i->len)
	{
		if (flags.zero)
			if (i->neg < 0 && i->flag == 0)
			{
				c += ft_putchar('-');
				i->flag = 1;
			}
		i->count += ft_width(flags.width + i->neg, i->len + i->count,
			flags.zero);
	}
	return (c);
}

static int	ft_third(t_flags flags, t_int *i, char *str)
{
	int c;

	c = 0;
	if (flags.minus == 0)
	{
		if (i->neg < 0 && i->flag == 0)
			c += ft_putchar('-');
		i->count += ft_width(flags.precision, i->len, 1);
		c += ft_putstr(str);
	}
	return (c);
}

int			ft_conversion_integer(int c, t_flags flags)
{
	t_int	i;
	char	*str;
	int 	cn;

	cn = 0;
	i = ft_init_int();
	if (c == -2147483648)
		i.flag = 1;
	if (c < 0)
	{
		c *= -1;
		i.neg = -1;
	}
	str = ft_itoa(c);
	i.len = ft_strlen(str);
	if (flags.precision == 0 && c == 0)
	{
		str = ft_strdup("");
		return (ft_width(flags.width, 0, flags.zero));
	}
	cn += ft_first(flags, &i, str);
	if (flags.zero > 0)
		if (flags.precision <= i.len && flags.precision > 0)
			flags.zero = 0;
	cn += ft_second(flags, &i);
	cn += ft_third(flags, &i, str);
	return (i.count + cn);
}
