/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:44:27 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/01 17:22:22 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	window_display(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (MALLOC_ERROR);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->map->cols * WIN_WIDTH, game->map->rows * WIN_HEIGHT, "so_long");
	if (game->mlx_win == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		error_message("Error\nCouldn't create the window.\n");
		return (MALLOC_ERROR);
	}
	return (1);
}

int	render_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (game->map->map[y][x] == '1')
					mlx_put_image_to_window(game->mlx_ptr, game->mlx_ptr, &game->wall, 32, 32);
			else if (game->map->map[y][x] == '0')
					mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, &game->floor, 32, 32);
			x++;
		}
		y++;
	}
	return (1);
}

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
	game->coin = new_sprite(game->mlx_ptr, "../sprite/coin.xpm", game);
	game->doorclosed = new_sprite(game->mlx_ptr, "../sprite/doorclosed.xpm", game);
	game->dooropen = new_sprite(game->mlx_ptr, "../sprite/dooropen.xpm", game);
	game->floor = new_sprite(game->mlx_ptr, "../sprite/floor.xpm", game);
	game->player = new_sprite(game->mlx_ptr, "../sprite/player.xpm", game);
	game->wall = new_sprite(game->mlx_ptr, "../sprite/wall.xpm", game);
}
