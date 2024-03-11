/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:22:32 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/11 16:34:01 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	game->wall.img = NULL;
}

void	create_sprite(t_game *game)
{
	init_sprite(game);
	game->coin = new_sprite(game->mlx_ptr, "srcs/img/coin.xpm", game);
	game->doorclosed = new_sprite(game->mlx_ptr, "srcs/img/door1.xpm", game);
	game->dooropen = new_sprite(game->mlx_ptr, "srcs/img/door2.xpm", game);
	game->floor = new_sprite(game->mlx_ptr, "srcs/img/floor.xpm", game);
	game->player = new_sprite(game->mlx_ptr, "srcs/img/player.xpm", game);
	game->wall = new_sprite(game->mlx_ptr, "srcs/img/wall.xpm", game);
}

int	collectible_check(t_game *game)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (game->map->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	if (count == 0)
		return (1);
	return (0);
}

void	end_prog(t_game *game, int y, int x, int keysym)
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
