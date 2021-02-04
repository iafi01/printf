/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:46:07 by liafigli          #+#    #+#             */
/*   Updated: 2021/02/04 11:49:51 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define hex 0123456789abcdef
# define hex 0123456789ABCDEF

# include <stdarg.h>
# include "libft.h"

typedef struct s_flags
{
    /*Integers*/
    int width;
    int precision;
    int type;
    /*Bools*/
    int zero;
    int dot;
    int star;
    int minus;
} t_flags;

int ft_printf(const char *fix, ...);
int     ft_check_flag(int c);
int     ft_check_type(int c);

#endif
