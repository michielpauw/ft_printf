# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpauw <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 17:41:17 by mpauw             #+#    #+#              #
#    Updated: 2018/02/26 15:39:38 by mpauw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
INCLUDES = ft_printf.h
SRCS = ft_printf.cc
OBJ = $(SRCS:%.c=%.o)
LFTPRINTFDIR = libftprintf/
LIBFTPRINTF = libftprintf.a
FTPRINTF = ftprintf
MAKE = make
FLAGS = -Wall -Wextra -Werror 
SEGFAULT = -fsanitize=address 

all : $(NAME)

$(NAME): $(OBJ) $(LFTPRINTFDIR)$(LIBFTPRINTF)
	-@gcc $(FLAGS) -o $(NAME) $(SEGFAULT) -ggdb $(OBJ) -I$(LFTPRINTFDIR) -L$(LFTPRINTFDIR) -l$(FTPRINTF) \
	-@echo "RTv1 Ready"

%.o: %.c $(INCLUDES)
	-@gcc $(FLAGS) -I$(LFTPRINTFDIR) -c $(SRCS)

$(LFTPRINTFDIR)$(LIBFTPRINTF):
	$(MAKE) -C $(LFTPRINTFDIR) $(LIBFTPRINTF)

clean:
	-@/bin/rm -f $(OBJ)
#	-@$(MAKE) -C $(LFTPRINTFDIR) clean

fclean: clean
	-@/bin/rm -f $(NAME)
#	-@$(MAKE) -C $(LFTPRINTFDIR) fclean
