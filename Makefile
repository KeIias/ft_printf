# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algautie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 15:08:42 by algautie          #+#    #+#              #
#    Updated: 2019/09/16 15:44:22 by algautie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

CC = 		gcc

CFLAGS = 	-Wall -Wextra -Werror

LIBPATH = 	./sources/libft/

SRC = 		./sources/conv_c.c \
			./sources/conv_d.c \
			./sources/conv_f.c \
			./sources/conv_f_extra.c \
.			./sources/conv_o.c \
.			./sources/conv_p.c \
.			./sources/conv_percent.c \
.			./sources/conv_s.c \
.			./sources/conv_u.c \
.			./sources/ft_printf.c \
.			./sources/get_stuff.c \
.			./sources/init.c \
			./sources/parsing.c \
			./sources/print_stuff.c \
			./sources/print_text.c \

OBJ = 		$(SRC:.c=.o)

$(NAME):
	@make -C $(LIBPATH) -j
	@ar rc $(NAME) $(SRC)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm  -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
