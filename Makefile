# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agras <agras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 01:48:03 by agras             #+#    #+#              #
#    Updated: 2022/01/27 11:45:00 by agras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= 	ft_printf.c\
				utils.c\
				utils_bis.c\
				convert_tochar.c\
				convert_toint.c\
				convert_tolowhex.c\
				convert_topointer.c\
				convert_tostr.c\
				convert_touint.c\
				convert_touphex.c\
				
OBJS		= ${SRCS:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f


.c.o:
		${CC} ${CFLAGS} -I./headers/ -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}

all: 		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re