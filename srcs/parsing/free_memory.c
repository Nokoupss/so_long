/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:59:32 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/06 16:12:37 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	if (game->wall.img)
		mlx_destroy_image(game->mlx_ptr, game->wall.img);
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
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(EXIT_FAILURE);
}
