# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 19:13:15 by tefroiss          #+#    #+#              #
#    Updated: 2022/01/03 16:50:29 by tefroiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

SRCS	=	megaphone.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC		=	clang++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

CLEAN	=	clean

#############################################################################
#									MAKE									#
#############################################################################

%.o			:	%.cpp
				$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re