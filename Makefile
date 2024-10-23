# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 15:36:16 by nbelkace          #+#    #+#              #
#    Updated: 2024/10/10 18:43:55 by nbelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS = so_long_bonus

# Directory
SRCS = srcs
GAME = game
PARSING = parsing
UTILS = utils
BONUS = bonus

# Utils Directory
UTILS_C = $(SRCS)/$(UTILS)
UTILS_C_BONUS = $(BONUS)/$(SRCS)/$(UTILS)

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

SRCS_C_BONUS =	$(BONUS)/$(SRCS)/$(GAME)/display_bonus.c \
				$(BONUS)/$(SRCS)/$(GAME)/game_utils_bonus.c \
				$(BONUS)/$(SRCS)/$(GAME)/game_utils2_bonus.c \
				$(BONUS)/$(SRCS)/$(GAME)/key_handler_bonus.c \
				$(BONUS)/$(SRCS)/$(GAME)/render_map_bonus.c \
				$(BONUS)/$(SRCS)/$(GAME)/render_player_bonus.c \
				$(BONUS)/$(SRCS)/$(PARSING)/check_arguments_bonus.c \
				$(BONUS)/$(SRCS)/$(PARSING)/check_map_bonus.c \
				$(BONUS)/$(SRCS)/$(PARSING)/check_map_utils_bonus.c \
				$(BONUS)/$(SRCS)/$(PARSING)/check_map_utils2_bonus.c \
				$(BONUS)/$(SRCS)/$(PARSING)/free_memory_bonus.c \
				$(BONUS)/$(SRCS)/$(PARSING)/init_map_bonus.c \
				$(BONUS)/$(SRCS)/$(PARSING)/path_finding_bonus.c \
				$(BONUS)/main.c \

# Object FIles
OBJS = ${SRCS_C:.c=.o}

OBJS_BONUS = ${SRCS_C_BONUS:.c=.o}

# Archive and Libraries
ARCHIVE = minilibx-linux/libmlx_Linux.a
LIBFT = $(UTILS_C)/libft/libft.a
LIBFT_BONUS = $(UTILS_C_BONUS)/libft/libft.a 

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

bonus : ${NAME_BONUS}

${NAME_BONUS} : ${OBJS_BONUS}
	make -C minilibx-linux
	make -C $(UTILS_C_BONUS)/libft
	${CC} -o ${NAME_BONUS} ${OBJS_BONUS} ${ARCHIVE} ${LIBFT_BONUS} ${X11_FLAGS}

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean :
	make -C $(UTILS_C)/libft clean
	make -C $(UTILS_C_BONUS)/libft clean
	${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	make -C $(UTILS_C)/libft fclean
	${RM} ${NAME} ${NAME_BONUS} ${OBJS_BONUS}

re : fclean all

.PHONY: all bonus clean fclean re