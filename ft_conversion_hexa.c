/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:39:11 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/18 11:08:35 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_first(t_flags flags, t_int *i, char *str)
{
	if (flags.minus == 1)
	{
		i->count += ft_width(flags.precision, i->len, 1);
		ft_putstr(str);
	}
}

static void	ft_second(t_flags flags, t_int *i)
{
	if (flags.precision > i->len)
		i->count = ft_width(flags.width, flags.precision,
		flags.width <= flags.precision);
	else if (flags.precision <= i->len)
		i->count = ft_width(flags.width, i->len + i->count, flags.zero);
}

static void	ft_third(t_flags flags, t_int *i, char *str)
{
	if (flags.minus == 0)
	{
		ft_width(flags.precision, i->len, 1);
		ft_putstr(str);
	}
}

int			ft_conversion_hexa(unsigned int c, int cap, t_flags flags)
{
	t_int	i;
	char	*str;

	i = ft_init_int();
	str = ft_baseall(c, 16, cap);
	i.len = ft_strlen(str);
	if (flags.precision == 0 && c == 0)
	{
		str = ft_strdup("");
		return (ft_width(flags.width, 0, flags.zero));
	}
	ft_first(flags, &i, str);
	if (flags.zero > 0)
		if (flags.precision < i.len && flags.precision > 0)
			flags.zero = 0;
	ft_second(flags, &i);
	ft_third(flags, &i, str);
	return (i.count + i.len);
}
