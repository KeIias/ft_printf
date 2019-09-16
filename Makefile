# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algautie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 15:08:42 by algautie          #+#    #+#              #
#    Updated: 2019/09/16 16:58:21 by algautie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

CC = 		gcc

CFLAGS = 	-Wall -Wextra -Werror

SRC_NAME = 		conv_c.c \
					conv_d.c \
					conv_f.c \
					conv_f_extra.c \
.					conv_o.c \
.					conv_p.c \
.			conv_percent.c \
.			conv_s.c \
.			conv_u.c \
.			ft_printf.c \
.			get_stuff.c \
.			init.c \
			parsing.c \
			print_stuff.c \
			print_text.c \

SRC_PATH = ./sources/

INC_NAME = ft_printf.h

INC_PATH = ./includes/

OBJ_PATH = ./objs/

LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a

INC = $(addprefix $(INC_PATH), $(INC_NAME))

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

all: $(NAME)

$(LIBFT_PATH)$(LIBFT_NAME):
	@make -C $(LIBFT_PATH) -j

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I $(INCLUDE_PATH) -I $(LIBFT_PATH)include/ \
	 	-c $< -o $@
clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
