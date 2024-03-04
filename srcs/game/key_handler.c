/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:22:41 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/04 18:05:44 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	escape_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		free_all_memory(game);
		ft_printf("CLOSE GAME\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	check_possible_move(int keysym, t_game *game)
{
	int	y;
	int	x;

	y = game->map->player_y;
	x = game->map->player_x;
	if (keysym == XK_Up)
	{
		if (game->map->map[y - 1][x] == '1')
			return (0);
	}
	else if (keysym == XK_Left)
	{
		if (game->map->map[y][x - 1] == '1')
			return (0);
	}
	else if (keysym == XK_Down)
	{
		if (game->map->map[y + 1][x] == '1')
			return (0);
	}
	else if (keysym == XK_Right)
		if (game->map->map[y][x + 1] == '1')
			return (0);
	return (1);
}

void	player_move(int keysym, t_game *game)
{
	if (keysym == XK_Up)
	{
		game->map->map[game->map->player_y][game->map->player_x] = '0';
		game->map->player_y--;
		game->map->map[game->map->player_y][game->map->player_x] = 'P';
	}
	else if (keysym == XK_Left)
	{
		game->map->map[game->map->player_y][game->map->player_x] = '0';
		game->map->player_x--;
		game->map->map[game->map->player_y][game->map->player_x] = 'P';
	}
	else if (keysym == XK_Down)
	{
		game->map->map[game->map->player_y][game->map->player_x] = '0';
		game->map->player_y++;
		game->map->map[game->map->player_y][game->map->player_x] = 'P';
	}
	else if (keysym == XK_Right)
	{
		game->map->map[game->map->player_y][game->map->player_x] = '0';
		game->map->player_y++;
		game->map->map[game->map->player_y][game->map->player_x] = 'P';
	}
}

void	movement(t_game *game, int keysym, int y, int x)
{
	if (collectible_check(game) == 1)
		end_prog(game, y, x, keysym);
	if (check_possible_move(keysym, game) == 1)
		player_move(keysym, game);
}

void	keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		escape_input(keysym, game);
	if (keysym == XK_Up)
		movement(game, keysym, game->map->player_y - 1, game->map->player_x);
	if (keysym == XK_Left)
		movement(game, keysym, game->map->player_y, game->map->player_x - 1);
	if (keysym == XK_Down)
		movement(game, keysym, game->map->player_y + 1, game->map->player_x);
	if (keysym == XK_Right)
		movement(game, keysym, game->map->player_y, game->map->player_x + 1);
}
