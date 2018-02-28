# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpauw <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:06:44 by mpauw             #+#    #+#              #
#    Updated: 2018/02/02 11:29:52 by mpauw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_convert_base.c/
		ft_isalnum.c/
		ft_isalpha.c/
		ft_isascii.c/
		ft_isdigit.c/
		ft_isprint.c/
		ft_memalloc.c/
		ft_memccpy.c/
		ft_memchr.c/
		ft_memcmp.c/
		ft_memcpy.c/
		ft_memdel.c/
		ft_memmove.c/
		ft_memset.c/
		ft_numlen.c/
		ft_putchar.c/
		ft_putnbr.c/
		ft_putstr.c/
		ft_realloc.c/
		ft_strcat.c/
		ft_strchr.c/
		ft_strclr.c/
		ft_strcmp.c/
		ft_strcpy.c/
		ft_strdel.c/
		ft_strdup.c/
		ft_strequ.c/
		ft_striter.c/
		ft_striteri.c/
		ft_strjoin.c/
		ft_strlcat.c/
		ft_strlen.c/
		ft_strmap.c/
		ft_strmapi.c/
		ft_strncat.c/
		ft_strncmp.c/
		ft_strncpy.c/
		ft_strnequ.c/
		ft_strnew.c/
		ft_strnstr.c/
		ft_strrchr.c/
		ft_strsplit.c/
		ft_strstr.c/
		ft_strsub.c/
		ft_strtrim.c/
		ft_tolower.c/
		ft_toupper.c
POINTO = $(SRC:%.c=%.o)
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
INCLUDE_HEADER = -I.

all: $(NAME)

$(NAME): $(POINTO)
	-@ar rc $(NAME) $(POINTO) && ranlib $(NAME)
	-@echo "Libftprintf ready"

%.o: %.c $(INCLUDES)
	-@gcc -ggdb $(FLAGS) $(INCLUDE_HEADER) $(FLAGS) -c $(SRC)

clean:
	-@/bin/rm -f $(POINTO)

fclean: clean
	-@/bin/rm -f $(NAME)

re: fclean all
