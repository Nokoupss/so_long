/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:38:19 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/11 16:32:53 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../minilibx-linux/mlx.h"
# include "../srcs/utils/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
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
	int		ennemy;
	int		player_y;
	int		player_x;
	int		count;
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
	t_img	playerup;
	t_img	playerdown;
	t_img	playerleft;
	t_img	slime;
	t_img	wall;
	t_map	*map;
}				t_game;

/*
**Game
*/
/*
**display_bonus
*/

int		window_display(t_game *game);
void	render_all(t_game *game, int keysym);
/*
**Game
*/
/*
**game_utils_bonus
*/

t_img	new_sprite(void *mlx, char *path, t_game *game);
void	init_sprite(t_game *game);
void	create_sprite(t_game *game);
void	end_prog_victory(t_game *game, int y, int x, int keysym);
void	end_prog_defeat(t_game *game, int y, int x, int keysym);

/*
**Game
*/
/*
**game_utils2_bonus
*/

int		collectible_check(t_game *game);
void	print_move(t_game *game);

/*
**Game
*/
/*
**key_handler_bonus
*/

int		escape_input(int keysym, t_game *game);
int		check_possible_move(int keysym, t_game *game);
void	player_move_character(int keysym, t_game *game);
void	movement(t_game *game, int keysym, int y, int x);
int		movement_input(int keysym, t_game *game);

/*
**Game
*/
/*
**render_map_bonus
*/

void	render_wall(t_game *game);
void	render_floor(t_game *game);
void	render_exit(t_game *game);
void	render_collectible(t_game *game);
void	render_ennemy(t_game *game);

/*
**Game
*/
/*
**render_player_bonus
*/

void	render_player_right(t_game *game);
void	render_player_down(t_game *game);
void	render_player_left(t_game *game);
void	render_player_up(t_game *game);

/*
**Parsing
*/
/*
**check_map_utils_bonus
*/

int		get_len_map(int fd, t_game *game);
void	error_message(char *str);
int		ft_strlen_backslash_n(char *str);
void	check_all_error(t_map *map, char *file, t_game *game);
void	check_len_map(t_map *map, t_game *game);

/*
**Parsing
*/
/*
**check_map_utils2_bonus
*/

int		check_map_characters_utils(t_map *map, char c);

/*
**Parsing
*/
/*
**check_arguments_bonus
*/

void	check_arguments(int argc);

/*
**Parsing
*/
/*
**check_map_bonus
*/

void	check_file_extension(char *file, t_game *game);
int		open_file(char *file, t_game *game);
void	check_rectangle(t_map *map, t_game *game);
int		check_map_characters(t_map *map);
void	check_map_outline(t_map *map, t_game *game);

/*
**Parsing
*/
/*
**free_memory_bonus
*/

void	destroy_images(t_game *game);
void	free_map(t_map *map);
void	free_copy_map(t_map *map);
int		free_all_memory(t_game *game);

/*
**Parsing
*/
/*
**init_map_bonus
*/

t_map	*init_map(void);
void	create_map(int fd, char *file, t_game *game);

/*
**Parsing
*/
/*
**path_finding_bonus
*/

void	create_copy(t_map *map);
int		player_position(t_map *map);
int		dfs(t_map *map, int y, int x);
void	check_path(t_map *map, t_game *game);

#endif