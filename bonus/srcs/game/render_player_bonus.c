/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:19:44 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/11 16:33:23 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_player_right(t_game *game)
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
			if (game->map->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->player.img, game->map->player_x * 32, \
				game->map->player_y * 32);
			x++;
		}
		y++;
	}
}

void	render_player_down(t_game *game)
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
			if (game->map->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->playerdown.img, game->map->player_x * 32, \
				game->map->player_y * 32);
			x++;
		}
		y++;
	}
}

void	render_player_left(t_game *game)
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
			if (game->map->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->playerleft.img, game->map->player_x * 32, \
				game->map->player_y * 32);
			x++;
		}
		y++;
	}
}

void	render_player_up(t_game *game)
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
			if (game->map->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
				game->playerup.img, game->map->player_x * 32, \
				game->map->player_y * 32);
			x++;
		}
		y++;
	}
}
