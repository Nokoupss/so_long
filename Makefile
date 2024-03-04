# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 15:36:16 by nbelkace          #+#    #+#              #
#    Updated: 2024/03/04 15:16:07 by nbelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Directory
SRCS = srcs
GAME = game
PARSING = parsing
UTILS = utils

# Utils Directory
UTILS_C = $(SRCS)/$(UTILS)

# Source Files
SRCS_C =	$(SRCS)/$(GAME)/display.c \
			$(SRCS)/$(GAME)/game_utils.c \
			$(SRCS)/$(GAME)/key_handler.c \
			$(SRCS)/$(GAME)/render_map.c \
			$(SRCS)/$(PARSING)/check_map_utils.c \
			$(SRCS)/$(PARSING)/check_map.c \
			$(SRCS)/$(PARSING)/free_memory.c \
			$(SRCS)/$(PARSING)/init_map.c \
			$(SRCS)/$(PARSING)/path_finding.c \
			main.c \

# Object FIles
OBJS = ${SRCS_C:.c=.o}

# Archive and Libraries
ARCHIVE = minilibx-linux/libmlx_Linux.a
LIBFT = $(UTILS_C)/libft/libft.a

# X11 Flags
X11_FLAGS = -L/usr/X11/lib -lXext -lX11 -lm

# Compiler and Flags
CC = cc
FLAGS = -Wall -Wextra -Werror -g3

# Remove command
RM = rm -f

# Rules
all : ${NAME}

${NAME} : ${OBJS}
	make -C minilibx-linux
	make -C $(UTILS_C)/libft
	${CC} -o ${NAME} ${OBJS} ${ARCHIVE} ${LIBFT} ${X11_FLAGS}

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean :
	make -C $(UTILS_C)/libft clean
	${RM} ${OBJS}

fclean : clean
	make -C $(UTILS_C)/libft fclean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re