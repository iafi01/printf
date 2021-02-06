/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:46:07 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/06 11:39:37 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define hex 0123456789abcdef
# define hex 0123456789ABCDEF

# include <stdarg.h>
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

int     ft_printf(const char *fix, ...);
int     ft_is_flags(int c);
int     ft_is_type(int c);
int     ft_check(char *s, va_list args);
int     ft_check_flags(const char *s, int i, t_flags *flags, va_list args);


#endif
