# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 01:03:03 by eassouli          #+#    #+#              #
#    Updated: 2019/12/18 21:02:54 by eassouli         ###   ########.fr        #
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

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o:		%.c
	$(CC) $(FLAGS) -o $@ -c $<
	
clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

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
	@echo "		      ______"
	@echo "		     | MINE |"
	@echo "		      ‾‾‾‾‾‾"
	@echo "--------------------------------------------------"
	@cat -b result_mine
	@echo "\n--------------------------------------------------"
	@echo "		      ______"
	@echo "		     | REAL |"
	@echo "		      ‾‾‾‾‾‾"
	@echo "--------------------------------------------------"
	@cat -b result_real
	@echo "\n--------------------------------------------------"
	@echo "		      ______"
	@echo "		     | DIFF |"
	@echo "		      ‾‾‾‾‾‾"
	@echo "=================================================="
	@diff result_mine result_real
	@echo "=================================================="
	@rm -f result_mine
	@rm -f result_real
