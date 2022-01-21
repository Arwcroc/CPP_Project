# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 17:23:42 by tefroiss          #+#    #+#              #
#    Updated: 2022/01/12 15:07:53 by tefroiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Bureaucrat

SRCS		=	Bureaucrat.cpp

MAIN		=	main.cpp

OBJS_MAIN 	= 	$(MAIN:.cpp=.o)
OBJS		=	$(SRCS:.cpp=.o)

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

CLEAN		=	clean

#############################################################################
#									MAKE									#
#############################################################################

%.o			:	%.cpp
				$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(OBJS_MAIN)
				${CC} ${CFLAGS} $(OBJS) $(OBJS_MAIN) -o ${NAME}

clean		:
				$(RM) $(OBJS)
				$(RM) $(OBJS_MAIN)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re