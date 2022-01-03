# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 14:23:51 by tefroiss          #+#    #+#              #
#    Updated: 2022/01/03 16:50:58 by tefroiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Annuaire

SRCS		=	Annuaire.cpp	\
				Contact.cpp

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