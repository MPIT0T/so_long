# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 14:28:25 by mpitot            #+#    #+#              #
#    Updated: 2024/01/30 14:41:13 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c

OBJS	=	${SRCS:%.c=${OBJ_D}%.o}

OBJ_D	=	objs/

NAME	=	so_long

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror #-g3

HEADER	=	so_long.h

all		:	${NAME}

${OBJS}	:	${OBJ_D}%.o: %.c libft/libft.h
			${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile
	make -C ./libft
	make -C ./mlx_linux
	${CC} ${CFLAGS} ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L./libft -lft -o ${NAME}

${OBJ_D}:
	@mkdir -p ${OBJ_D}

clean	:
	make clean -C ./libft
	make clean -C ./mlx_linux
	rm -rf ${OBJ_D}

fclean	:	clean
	make fclean -C ./libft
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re