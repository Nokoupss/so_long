/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:44:27 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/04 15:04:53 by nbelkace         ###   ########.fr       */
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

void	render_all(t_game *game)
{
	render_wall(game);
	render_floor(game);
	render_exit(game);
	render_collectible(game);
	render_player(game);
}
