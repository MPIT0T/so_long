# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 14:28:25 by mpitot            #+#    #+#              #
#    Updated: 2024/02/18 20:55:50 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c	\
check_map.c			\
map_solvability.c	\
parsing.c			\
movements.c			\
ft_mlx.c

OBJS	=	${SRCS:%.c=${OBJ_D}%.o}

SRC_D	=	srcs/

OBJ_D	=	objs/

NAME	=	so_long

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -Iincludes -g3

HEADER	=	so_long.h

all		:
	@make libft.a --no-print-directory -C ./libft
	@make --no-print-directory -C ./mlx_linux
	@make --no-print-directory ${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.c libft/incs/libft.h includes/so_long.h
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile includes/so_long.h libft/libft.a
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