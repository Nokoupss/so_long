/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:38:19 by nbelkace          #+#    #+#             */
/*   Updated: 2024/02/08 15:20:18 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../srcs/utils/libft/libft.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIDTH 400
# define HEIGHT 400 

# define EXIT_FAILURE 1
# define MALLOC_ERROR 0

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
}				t_game;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collectible;
	int		exit;
	int		player;
}				t_map;

/*
**check_map_utils
*/

int		get_len_map(int fd);
void	error_message(char *str);
int		ft_strlen_backslash_n(char *str);

/*
**check_map
*/

void	check_file_extension(char *file);
int		open_file(char *file);
void	check_rectangle(t_map *map);
int		check_map_characters(t_map *map);
void	check_map_outline(t_map *map);
void	check_all_error(t_map *map, char *file);

/*
**Game
*/

int		window_display(void);
int		escape_input(int keysym, t_game *data);

/*
**init_map.c
*/

t_map	*init_map(void);
t_map	*create_map(int fd, char *file);
void	free_map(t_map *map);

#endif