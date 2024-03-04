/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:38:19 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/04 18:05:07 by nbelkace         ###   ########.fr       */
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

# define WIN_WIDTH 32
# define WIN_HEIGHT 32 

# define EXIT_FAILURE 1
# define MALLOC_ERROR 0

typedef struct s_map
{
	char	**map;
	char	**map_copy;
	int		rows;
	int		cols;
	int		collectible;
	int		exit;
	int		player;
	int		exit_access;
	int		player_y;
	int		player_x;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	coin;
	t_img	doorclosed;
	t_img	dooropen;
	t_img	floor;
	t_img	player;
	t_img	wall;
	t_map	*map;
}				t_game;

/*
**Game
*/
/*
**display
*/

int		window_display(t_game *game);
void	render_all(t_game *game);
/*
**Game
*/
/*
**game_utils
*/

t_img	new_sprite(void *mlx, char *path, t_game *game);
void	init_sprite(t_game *game);
int		collectible_check(t_game *game);
void	end_prog(t_game *game, int y, int x, int keysym);

/*
**Game
*/
/*
**key_handler
*/

int		escape_input(int keysym, t_game *game);
int		check_possible_move(int keysym, t_game *game);
void	player_move(int keysym, t_game *game);
void	movement(t_game *game, int keysym, int y, int x);
void	keypress(int keysym, t_game *game);

/*
**Game
*/
/*
**render_map
*/

void	render_wall(t_game *game);
void	render_floor(t_game *game);
void	render_exit(t_game *game);
void	render_collectible(t_game *game);
void	render_player(t_game *game);

/*
**Parsing
*/
/*
**check_map_utils
*/

int		get_len_map(int fd);
void	error_message(char *str);
int		ft_strlen_backslash_n(char *str);
void	check_all_error(t_map *map, char *file);

/*
**Parsing
*/
/*
**check_map
*/

void	check_file_extension(char *file);
int		open_file(char *file);
void	check_rectangle(t_map *map);
int		check_map_characters(t_map *map);
void	check_map_outline(t_map *map);

/*
**Parsing
*/
/*
**free_memory
*/

void	destroy_images(t_game *game);
void	free_map(t_map *map);
void	free_copy_map(t_map *map);
void	free_all_memory(t_game *game);

/*
**Parsing
*/
/*
**init_map
*/

t_map	*init_map(void);
t_map	*create_map(int fd, char *file);

/*
**Parsing
*/
/*
**path_finding
*/

void	create_copy(t_map *map);
int		player_position(t_map *map);
int		dfs(t_map *map, int y, int x);
void	check_path(t_map *map);

#endif