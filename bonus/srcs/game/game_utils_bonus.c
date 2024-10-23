/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjy <nadjy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:22:32 by nbelkace          #+#    #+#             */
/*   Updated: 2024/10/11 15:57:59 by nadjy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_img	new_sprite(void *mlx, char *path, t_game *game)
{
	t_img	image;

	image.img = mlx_xpm_file_to_image(mlx, path, &image.width, &image.height);
	if (image.img == NULL)
	{
		free_all_memory(game);
		error_message("Error\nFailed to load sprite.\n");
		exit(EXIT_FAILURE);
	}
	return (image);
}

void	init_sprite(t_game *game)
{
	game->coin.img = NULL;
	game->doorclosed.img = NULL;
	game->dooropen.img = NULL;
	game->floor.img = NULL;
	game->player.img = NULL;
	game->playerdown.img = NULL;
	game->playerleft.img = NULL;
	game->playerup.img = NULL;
	game->wall.img = NULL;
	game->slime.img = NULL;
}

void	create_sprite(t_game *game)
{
	game->coin = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/coin.xpm", game);
	game->doorclosed = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/door1.xpm", game);
	game->dooropen = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/door2.xpm", game);
	game->floor = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/floor.xpm", game);
	game->player = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/player.xpm", game);
	game->playerdown = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/playerdown.xpm", game);
	game->playerleft = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/playerleft.xpm", game);
	game->playerup = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/playerup.xpm", game);
	game->wall = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/wall.xpm", game);
	game->slime = new_sprite(game->mlx_ptr, \
	"bonus/srcs/img_bonus/slime.xpm", game);
}

void	end_prog_victory(t_game *game, int y, int x, int keysym)
{
	if (game->map->map[y][x] == 'E')
	{
		player_move_character(keysym, game);
		ft_printf("\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
");
		free_all_memory(game);
	}
}

void	end_prog_defeat(t_game *game, int y, int x, int keysym)
{
	if (game->map->map[y][x] == 'S')
	{
		player_move_character(keysym, game);
		ft_printf("\n\
██████████████████████████████████████████████████████████████████████\n\
██                                                                  ██\n\
██  ███  ███  ██████  ██    ██     ██     ██████    ██████  ██████  ██\n\
██   ██  ██  ██    ██ ██    ██     ██    ██    ██   ██      ██      ██\n\
██    ████   █      █ ██    ██     ██    █      █   ██████  ██████  ██\n\
██     ██    ██    ██ ██    ██     ██    ██    ██       ██  ██      ██\n\
██     ██     ██████    ████       ████   ██████    ██████  ██████  ██\n\
██                                                                  ██\n\
██████████████████████████████████████████████████████████████████████\n\n\
");
		free_all_memory(game);
	}
}
