# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 14:28:25 by mpitot            #+#    #+#              #
#    Updated: 2024/01/27 14:43:31 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c

OBJS	=	${SRCS:.c=.o}

NAME	=	so_long

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror #-g3

HEADER	=	so_long.h

all		:	${NAME}

%.c		:	%.o ${HEADER} libft/libft.h printf/ft_printf.h
	${CC} ${CFLAGS} I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}	:	${OBJS} Makefile
	make -C ./libft
	make -C ./printf
	${CC} ${CFLAGS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L./libft -lft -L./printf -lftprintf -o ${NAME}

clean	:
	make clean -C ./libft
	make clean -C ./printf
	rm -f ${OBJS}

fclean	:	clean
	make fclean -C ./libft
	make fclean -C ./printf
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re