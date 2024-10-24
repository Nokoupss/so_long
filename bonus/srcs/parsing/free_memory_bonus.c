/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:59:32 by nbelkace          #+#    #+#             */
/*   Updated: 2024/10/21 12:25:16 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	destroy_images(t_game *game)
{
	if (game->coin.img)
		mlx_destroy_image(game->mlx_ptr, game->coin.img);
	if (game->doorclosed.img)
		mlx_destroy_image(game->mlx_ptr, game->doorclosed.img);
	if (game->dooropen.img)
		mlx_destroy_image(game->mlx_ptr, game->dooropen.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx_ptr, game->floor.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx_ptr, game->player.img);
	if (game->playerdown.img)
		mlx_destroy_image(game->mlx_ptr, game->playerdown.img);
	if (game->playerup.img)
		mlx_destroy_image(game->mlx_ptr, game->playerup.img);
	if (game->playerleft.img)
		mlx_destroy_image(game->mlx_ptr, game->playerleft.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx_ptr, game->wall.img);
	if (game->slime.img)
		mlx_destroy_image(game->mlx_ptr, game->slime.img);
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return ;
	if (map->map != NULL)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	free(map);
}

void	free_copy_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map->map_copy[i])
	{
		free(map->map_copy[i]);
		i++;
	}
	free(map->map_copy);
}

int	free_all_memory(t_game *game)
{
	destroy_images(game);
	free_map(game->map);
	if (game->mlx_ptr)
	{
		if (game->mlx_win)
			mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
	}
	free(game->mlx_ptr);
	free(game);
	exit(EXIT_FAILURE);
}

int	free_close(t_game *game)
{
	free_map(game->map);
	close(game->fd);
	free(game);
	exit(EXIT_FAILURE);
}
