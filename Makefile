# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 01:03:03 by eassouli          #+#    #+#              #
#    Updated: 2019/12/12 09:34:20 by eassouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c \
				ft_writenum.c \
				ft_writechars.c \
				ft_printf_utils.c \
				ft_buffer.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -I $(HEADER)

HEADER		= .

RM			= rm -f

_BLACK		= \033[30m
_BLACKBG	= \033[40m
_RED		= \033[31m
_REDBG		= \033[41m
_GREEN		= \033[32m
_GREENBG	= \033[42m
_YELLOW		= \033[33m
_YELLOWBG	= \033[43m
_BLUE		= \033[34m
_BLUEBG		= \033[44m
_PINK		= \033[35m
_PINKBG		= \033[45m
_CYAN		= \033[36m
_CYANBG		= \033[46m
_GREY		= \033[37m
_GERYBG		= \033[47m
_ENDL		= \033[0m
_BOLD		= \033[1m
_UL			= \033[4m
_FLASH		= \033[5m
_L			= \033[6m

T = $(words $(OBJS))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C '*' 100 / $T`%]"

all:		$(NAME)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS) && printf "%b\n" "$(_GREEN)[115%] Compilation Success !\nlibftprintf.a $(_GREEN)successfully created !$(_ENDL)"
	@ranlib $(NAME)

%.o:		%.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf "%-128b\r" "$(_GREEN)$(ECHO)$(_CYAN) Compiling $@"
	
clean:
	$(RM) $(OBJS)
	@echo "$(_CYAN)Clean done !$(_ENDL)"

fclean:		clean
	$(RM) $(NAME)
	@echo "$(_CYAN)Library removed !$(_ENDL)"

re:			fclean all

.PHONY:		all clean fclean re

f: all
	@gcc -g -Wall -Wextra -Werror libftprintf.a main/main.c -o mine.out
	@./mine.out > result_mine
	@rm -f mine.out
	@rm -rf mine.out.dSYM/
	@gcc -Wall -Wextra -Werror main/main2.c -o real.out
	@./real.out > result_real
	@rm -f real.out
	@echo "$(_CYAN)		      ______"
	@echo "		     | MINE |"
	@echo "		      ‾‾‾‾‾‾"
	@echo "--------------------------------------------------$(_ENDL)"
	@cat -b result_mine
	@echo "\n$(_CYAN)--------------------------------------------------"
	@echo "		      ______"
	@echo "		     | REAL |"
	@echo "		      ‾‾‾‾‾‾"
	@echo "--------------------------------------------------$(_ENDL)"
	@cat -b result_real
	@echo "\n$(_CYAN)--------------------------------------------------"
	@echo "		      ______"
	@echo "		     | DIFF |"
	@echo "		      ‾‾‾‾‾‾"
	@echo "==================================================$(_RED)"
	@diff result_mine result_real
	@echo "$(_CYAN)==================================================$(_ENDL)"
	@rm -f result_mine
	@rm -f result_real
