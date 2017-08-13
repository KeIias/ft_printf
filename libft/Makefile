# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 10:24:42 by agautier          #+#    #+#              #
#    Updated: 2016/12/18 20:15:48 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc -c -Wall -Wextra -Werror
SRC = ft_putchar.c ft_putstr.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_bzero.c\
	  ft_memchr.c ft_memcmp.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strchr.c\
	  ft_atoi.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
	  ft_memalloc.c ft_memdel.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr_fd.c ft_strcat.c ft_isalnum.c\
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strequ.c ft_striter.c\
	  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strmap.c ft_strmapi.c\
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c\
	  ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
	  ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstadd.c ft_lstdel.c ft_wnbr.c\
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_ismathoperator.c\
	  ft_ischarspace.c ft_putnbrendl.c ft_putnbrendl_fd.c ft_islow.c ft_isup.c\
	  ft_lstrev.c ft_strccat.c ft_strcjoin.c ft_strclen.c

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
