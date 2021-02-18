/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/18 18:08:27 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_first(t_flags flags, t_int *i, char *str)
{
	int c;

	c = 0;
	if (flags.minus == 1)
	{
		i->count += ft_width(flags.precision, i->len, 1);
		c += ft_putstr(str);
	}
	return (c);
}

static void	ft_second(t_flags flags, t_int *i)
{
	if (flags.precision > i->len)
		i->count += ft_width(flags.width, flags.precision,
		flags.width <= flags.precision);
	else if (flags.precision <= i->len)
		i->count += ft_width(flags.width, i->len + i->count, flags.zero);
}

static int	ft_third(t_flags flags, t_int *i, char *str)
{
	int c;

	c = 0;
	if (flags.minus == 0)
	{
		c += ft_width(flags.precision, i->len, 1);
		c += ft_putstr(str);
	}
	return (c);
}

int			ft_conversion_unsigned(unsigned int c, t_flags flags)
{
	t_int	i;
	char	*str;
	int		cn;

	cn = 0;
	i = ft_init_int();
	str = ft_itoa_u(c);
	i.len = ft_strlen(str);
	if (flags.precision == 0 && c == 0)
	{
		str = ft_strdup("");
		return (ft_width(flags.width, 0, flags.zero));
	}
	cn += ft_first(flags, &i, str);
	if (flags.zero > 0)
		if (flags.precision < i.len && flags.precision > 0)
			flags.zero = 0;
	ft_second(flags, &i);
	cn += ft_third(flags, &i, str);
	return (i.count + cn);
}
