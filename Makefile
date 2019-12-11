# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 01:03:03 by eassouli          #+#    #+#              #
#    Updated: 2019/12/11 18:41:30 by eassouli         ###   ########.fr        #
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
	@ar rc $(NAME) $(OBJS) && echo "$(_GREEN)[100%] Compilation Success$(_ENDL)"
	@ranlib $(NAME)

%.o:		%.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf "%-60b\r" "$(_GREEN)$(ECHO)$(_CYAN) Compiling $@"
	
clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

f: all
	@gcc -g -Wall -Wextra -Werror ft_printf.a main/main.c -o mine.out
	@./mine.out > result_mine
	@rm -f mine.out
	@rm -rf mine.out.dSYM/
	@gcc -Wall -Wextra -Werror main/main2.c -o real.out
	@./real.out > result_real
	@rm -f real.out
	@echo "Mine :"
	@echo "-----------------------------------"
	@cat result_mine
	@echo "\n-----------------------------------\n"
	@echo "Real :"
	@echo "-----------------------------------"
	@cat result_real
	@echo "\n-----------------------------------\n"
	@echo "Diff :"
	@echo "===================================$(_RED)"
	@diff result_mine result_real
	@echo "$(_ENDL)==================================="
	@rm -f result_mine
	@rm -f result_real
