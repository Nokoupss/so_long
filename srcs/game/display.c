/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:44:27 by nbelkace          #+#    #+#             */
/*   Updated: 2024/02/29 18:27:31 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	window_display(void)
{
	t_game	game;
	
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (MALLOC_ERROR);
	game.mlx_win = mlx_new_window(game.mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "youhou");
	if (game.mlx_win == NULL)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		return (MALLOC_ERROR);
	}
	mlx_loop(game.mlx_ptr);
	mlx_destroy_window(game.mlx_ptr, game.mlx_win);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
	return (0);
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
					mlx_put_image_to_window(game->mlx_ptr, game->mlx_ptr, game->wall, 32, 32);
			if (game->map->map[y][x] == '0')
					mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->floor, 32, 32);
			x++;
		}
		y++;
	}
	return (1);
}

void	init_sprite(t_game *game)
{
	*game->width = 32;
	*game->height = 32;
	game->coin = mlx_xpm_file_to_image(game->mlx_ptr, "../images/coin.xpm", game->width, game->height);
	game->doorclosed = mlx_xpm_file_to_image(game->mlx_ptr, "../images/doorclosed.xpm", game->width, game->height);
	game->dooropen = mlx_xpm_file_to_image(game->mlx_ptr, "../images/dooropen.xpm", game->width, game->height);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "../images/floor.xpm", game->width, game->height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "../images/player.xpm", game->width, game->height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "../image/wall.xpm", game->width, game->height);
	render_background(game);
}
