# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 01:03:03 by eassouli          #+#    #+#              #
#    Updated: 2020/02/09 23:00:54 by eassouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c \
				ft_flags.c \
				ft_printf_utils.c \
				ft_writechars.c \
				ft_writenum.c \

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
