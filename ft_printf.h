/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:46:07 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/18 18:52:04 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int			width;
	int			precision;
	int			type;
	int			zero;
	int			dot;
	int			star;
	int			minus;
}				t_flags;

typedef struct	s_int
{
	int			count;
	int			len;
	int			minus;
	int			neg;
	int			flag;
	int			cn;
}				t_int;

t_int			ft_init_int(void);
char			*ft_lowercase(char *s);
char			*ft_itoa_u(unsigned int n);
int				ft_printf(const char *fix, ...);
int				ft_is_flags(int c);
int				ft_is_type(int c);
t_flags			ft_flag_minus(t_flags flags);
int				ft_flag_dot(const char *s, int i, t_flags *flags, va_list args);
int				ft_check_flags(const char *s, int i, t_flags *flags,
					va_list args);
int				ft_check(char *s, va_list args);
char			*ft_baseall(unsigned long long n, int base, int up);
int				ft_width(int width, int leng, int zero);
char			*ft_itoa_u(unsigned int n);
int				ft_conversion(int c, t_flags flags, va_list args);
int				ft_conversion_char(int c, t_flags flags);
int				ft_conversion_string(char *str, t_flags flags);
int				ft_conversion_pointer(unsigned long long c, t_flags flags);
int				ft_conversion_hexa(unsigned int c, int cap, t_flags flags);
int				ft_conversion_integer(int c, t_flags flags);
int				ft_conversion_unsigned(unsigned int c, t_flags flags);
int				ft_conversion_percent(t_flags flags);

#endif
