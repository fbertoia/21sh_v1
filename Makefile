# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbertoia <fbertoia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 11:38:20 by fbertoia          #+#    #+#              #
#    Updated: 2018/02/04 01:58:03 by fbertoia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
CC = gcc
INCLUDES_DIR = includes
CFLAGS = -Wall -Wextra -Werror -g3
export CFLAGS
CFLAGS++ = -ltermcap
IFLAGS = -I$(INCLUDES_DIR)
INCLUDES = sh21.h ft_printf.h libft.h
VPATH = ./obj\
		:./srcs\
		:./srcs/main\
		:./includes\

SRCS = sh21.c
LIB = ./libft/libft.a
LIB_DIR = ./libft
OBJS = $(SRCS:.c=.o)
OBJS_PATH = ./obj
OBJS_WITH_PATH = $(OBJS:%.o=obj/%.o)
MAKEFILE = Makefile

.PHONY: all clean fclean re library printf

all: library $(NAME)

library:
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIB) $(INCLUDES) $(MAKEFILE)
	@$(CC) $(CFLAGS) $(CFLAGS++) $(IFLAGS) $(OBJS_WITH_PATH) $(LIB) -o $@
	@printf "\n[21SH] \033[1;32m===%s completed===\033[0m\n" "$(NAME)"

%.o: %.c $(INCLUDES) $(MAKEFILE)
	@printf "\r[21SH] \033[1;33mBuilding %s\033[0m" "$(NAME)"
	@$(CC) -o $(OBJS_PATH)/$@ -c $(CFLAGS) $(CFLAGS++) $(IFLAGS) $<

clean:
	@printf "[21SH] \033[1;31mDeleting %s objects\033[0m\n" "$(NAME)"
	@rm -f $(OBJS_WITH_PATH)
	@make -C ./libft clean

fclean: clean
	@printf "[21SH] \033[1;31mDeleting %s project \033[0m\n" "$(NAME)"
	@rm -f $(NAME)
	@printf "[21SH] \033[1;31mDeleting Libft library\033[0m\n"
	@rm -f ./libft/libft.a

re: fclean all
