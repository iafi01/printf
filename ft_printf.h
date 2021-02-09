/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:46:07 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/09 13:57:07 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define hex 0123456789abcdef
# define HEX 0123456789ABCDEF

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{
    /*Integers*/
    int printed;
    int width;
    int precision;
    int type;
    /*Bools*/
    int zero;
    int dot;
    int star;
    int minus;
} t_flags;

int             ft_printf(const char *fix, ...);
int             ft_is_flags(int c);
int             ft_is_type(int c);
int             ft_check(char *s, va_list args);
char            *ft_baseall(unsigned long long n, int base, int up);
int             ft_width(int width, int leng, int zero);
char			*ft_u_itoa(unsigned int n);
/*int     ft_check_flags(const char *s, int i, t_flags *flags, va_list args);
int     ft_conversion_char(va_arg(args, int), flags);
int     ft_conversion_string(va_arg(args, char*), flags);
int     ft_conversion_pointer(va_arg(args, unsigned long long), flags);
int     ft_conversion_hexa(va_arg(args, unsigned int), 1, flags);
int     ft_conversion_integer(va_arg(args, int), flags);
int     ft_conversion_unsigned(va_arg(args, unsigned int), flags);
int     ft_conversion_percent(flags);*/
#endif
