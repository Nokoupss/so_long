/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:12:01 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/11 13:49:45 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_wall(t_game *game)
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
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->wall.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	render_floor(t_game *game)
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
			if (game->map->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->floor.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	render_exit(t_game *game)
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
			if (game->map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->doorclosed.img, x * 32, y * 32);
			if (game->map->map[y][x] == 'E' && collectible_check(game) == 1)
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->dooropen.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	render_collectible(t_game *game)
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
			if (game->map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->coin.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	render_ennemy(t_game *game)
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
			if (game->map->map[y][x] == 'S')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->slime.img, x * 32, y * 32);
			x++;
		}
		y++;
	}	
}
