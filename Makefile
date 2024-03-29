# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 10:39:22 by liafigli          #+#    #+#              #
#    Updated: 2021/02/17 17:22:01 by liafigli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	=	-Wall -Wextra -Werror

RM		=	/bin/rm -f

NAME	=	libftprintf.a

INCLUDE = 	ft_printf.h

FILES	=	ft_baseall.c ft_conversion_char.c ft_conversion_hexa.c \
			ft_conversion_integer.c ft_conversion_percent.c \
			ft_conversion_pointer.c ft_conversion_string.c \
			ft_conversion_unsigned.c ft_converts.c ft_itoa_u.c \
			ft_printf.c ft_width.c ft_itoa_u.c ft_flags.c \
			ft_lowercase.c \
			
FILESS	=	 $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILESS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	gcc $(FLAGS) $(INCLUDE) $(SRCS)
	ar -rc $(NAME) $^

.c.o:
	gcc $(FLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(FILESS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all
