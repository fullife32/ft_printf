# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 01:03:03 by eassouli          #+#    #+#              #
#    Updated: 2019/12/10 03:38:22 by eassouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c \
				ft_writenum.c \
				ft_writechars.c \
				ft_printf_utils.c \
				ft_buffer.c

OBJS		= $(SRCS:.c=.o)

NAME		= ft_printf.a

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -I $(HEADER)

HEADER		= .

RM			= rm -f

_CYAN		= \033[36m
_GREEN		= \033[32m
_RED		= \033[31m
_ENDL		= \033[0m

T = $(words $(OBJS))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C '*' 100 / $T`%]"

all:		$(NAME)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS) && echo "$(_GREEN)[100%] LIBFT Compilation Success$(_ENDL)"
	@ranlib $(NAME)

%.o:		%.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf "%-60b\r" "$(_GREEN)$(ECHO)$(_CYAN) Compilation $@"

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

f: all
	@./test.sh
