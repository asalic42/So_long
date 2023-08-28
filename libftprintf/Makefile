# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalic <asalic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 16:11:40 by asalic            #+#    #+#              #
#    Updated: 2023/06/08 15:39:57 by asalic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

COMP = gcc -c $(CFLAGS)

SRC = ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnb.c \
	ft_putunb.c \
	ft_printhexa.c \
	ft_addrhexa.c

OBJ = $(SRC:.c=.o)

.c.o : $(COMP) $<

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean :
	@rm -f *.o

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
