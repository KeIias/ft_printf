# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 10:24:42 by agautier          #+#    #+#              #
#    Updated: 2017/08/03 12:50:45 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
GCC = gcc -c -Wall -Wextra -Werror
SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(GCC) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

e: all clean
