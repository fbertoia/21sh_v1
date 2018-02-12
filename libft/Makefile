# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 18:45:15 by fbertoia          #+#    #+#              #
#    Updated: 2018/02/06 10:37:55 by fbertoia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -Wall -Wextra -Werror -I $(INCLUDES_DIR)
INCLUDES = ft_printf.h libft.h
INCLUDES_DIR = ../includes
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INCLUDES_DIR)
VPATH=srcs\
	:srcs/char\
	:srcs/del\
	:srcs/i_o\
	:srcs/list\
	:srcs/maths\
	:srcs/str\
	:srcs/ft_printf\
	:./obj\
	:../includes

SRCS_LIBFT = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
	ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
	ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	ft_putstr.c ft_putstr_fd.c ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c \
	ft_tolower.c ft_toupper.c ft_max.c ft_abs.c ft_itoa_base.c ft_strrev.c \
	ft_strcapitalize.c ft_lstsize.c ft_strindex.c ft_strcdup.c ft_binsearch.c \
	ft_lstadd_back.c ft_strnindex.c ft_strlcpy.c ft_sortstrings.c get_next_line.c\
	ft_strsplitwhitespace.c size_list.c last_elem.c str_alnum.c ft_strndup.c\
	ft_strjoin_multiple.c del_arr.c del_str.c

SRCS_PRINTF = ft_printf.c ft_dprintf.c ft_print.c \
	ft_modifiers.c ft_flags.c ft_buffmgmt.c ft_box_initializer.c ptr_s.c ptr_smaj.c\
	ptr_c.c ptr_cmaj.c ptr_p.c ptr_pct.c ptr_d.c ptr_d_getnb.c ptr_u.c ptr_o.c\
	ptr_x.c ptr_lambda.c ptr_b.c ptr_unsigned_common.c ptr_unsigned_commonbis.c\
	ft_insert_spaces.c ptr_color.c

OBJS_PRINTF = $(SRCS_PRINTF:%.c=%.o)
OBJS_LIBFT = $(SRCS_LIBFT:%.c=%.o)
OBJS_PATH = ./obj
OBJS_WITH_PATH = $(addprefix $(OBJS_PATH)/, $(OBJS_PRINTF)) \
				$(addprefix $(OBJS_PATH)/, $(OBJS_LIBFT))
MAKEFILE = makefile

all: $(NAME)

$(NAME): $(OBJS_LIBFT) $(OBJS_PRINTF) $(INCLUDES) $(MAKEFILE)
	@printf "\n[21SH] \033[1;32m===%s completed===\033[0m\n" "$(NAME)"
	@ar rsc $(NAME) $(OBJS_WITH_PATH)

%.o: %.c $(INCLUDES) $(MAKEFILE)
	@printf "\r[21SH] \033[1;33mBuilding Libft $< \033[0m"
	@$(CC) -o $(OBJS_PATH)/$@ -c $(CFLAGS) $(IFLAGS) $<

clean:
	@printf "[21SH] \033[1;31mDeleting Libft objects\033[0m\n"
	@rm -f $(OBJS_WITH_PATH)

fclean: clean
	@printf "[21SH] \033[1;31mDeleting Libft library\033[0m\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft printf
