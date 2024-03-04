/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:22:32 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/04 18:04:50 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_img	new_sprite(void *mlx, char *path, t_game *game)
{
	t_img	sprite;

	sprite.img = mlx_xpm_file_to_image(mlx, path, &sprite.width, &sprite.height);
	if (sprite.img == NULL)
	{
		destroy_images(game);
		error_message("Error\nFailed to load sprite.\n");
	}
	return (sprite);
}

void	init_sprite(t_game *game)
{
	game->coin = new_sprite(game->mlx_ptr, "srcs/sprite/coin.xpm", game);
	game->doorclosed = new_sprite(game->mlx_ptr, "srcs/sprite/doorclosed.xpm", game);
	game->dooropen = new_sprite(game->mlx_ptr, "srcs/sprite/dooropen.xpm", game);
	game->floor = new_sprite(game->mlx_ptr, "srcs/sprite/floor.xpm", game);
	game->player = new_sprite(game->mlx_ptr, "srcs/sprite/player.xpm", game);
	game->wall = new_sprite(game->mlx_ptr, "srcs/sprite/wall.xpm", game);
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
		player_move(keysym, game);
		free_all_memory(game);
		ft_printf("YOU WIN\n");
	}
}
