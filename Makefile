# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algautie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 15:08:42 by algautie          #+#    #+#              #
#    Updated: 2019/09/18 11:34:39 by algautie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Text format
_DEF 		=	$'\033[0m
_END		=	$'\033[0m
_GRA		=	$'\033[1m
_SOUL		=	$'\033[4m
_CLIG		=	$'\033[5m
_SURL		=	$'\033[7m

# Color
_BLACK		=	$'\033[30m
_RED		=	$'\033[31m
_GREEN		=	$'\033[32m
_YELLOW		=	$'\033[33m
_BLUE		=	$'\033[34m
_PURPLE		=	$'\033[35m
_CYAN		=	$'\033[36m
_GREY		=	$'\033[37m

# Background
_IBLACK		=	$'\033[40m
_IRED		=	$'\033[41m
_IGREEN		=	$'\033[42m
_IYELLOW	=	$'\033[43m
_IBLUE		=	$'\033[44m
_IPURPLE	=	$'\033[45m
_ICYAN		=	$'\033[46m
_IGREY		=	$'\033[47m

NAME = 		libftprintf.a

CC = 		gcc

CFLAGS = 	-Wall -Wextra -Werror

SRC_NAME = 		conv_c.c \
				conv_d.c \
				conv_f.c \
				conv_f_extra.c \
				conv_o.c \
				conv_p.c \
				conv_percent.c \
				conv_s.c \
				conv_x.c \
				conv_u.c \
				ft_printf.c \
				get_stuff.c \
				init.c \
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

$(NAME): $(LIBFT_PATH)$(LIBFT_NAME) $(OBJ)
	@cp $(LIBFT_PATH)$(LIBFT_NAME) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I $(INC) -I $(LIBFT_PATH) -o $@ -c $<
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)\t" \
		"COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
