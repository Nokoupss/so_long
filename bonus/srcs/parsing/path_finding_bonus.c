/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:46:31 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/08 15:59:58 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	create_copy(t_map *map)
{
	int		y;
	int		j;

	map->map_copy = (char **)malloc((map->rows + 1) * sizeof(char *));
	if (map->map_copy == NULL)
		return ;
	y = 0;
	while (map->map[y] != NULL)
	{
		map->map_copy[y] = ft_strdup(map->map[y]);
		if (map->map_copy[y] == NULL)
		{
			j = 0;
			while (j < y)
			{
				free(map->map_copy[j]);
				j++;
			}
			free(map->map_copy);
			return ;
		}
		y++;
	}
	map->map_copy[y] = NULL;
}

int	player_position(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			if (map->map[y][x] == 'P')
			{
				map->player_y = y;
				map->player_x = x;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	dfs(t_map *map, int y, int x)
{
	if (map->map_copy[y][x] == '1')
		return (0);
	if (map->map_copy[y][x] == 'C')
		map->collectible--;
	if (map->map_copy[y][x] == 'E')
	{
		map->exit_access = 1;
		return (0);
	}
	map->map_copy[y][x] = '1';
	if (dfs(map, y - 1, x))
		return (1);
	if (dfs(map, y + 1, x))
		return (1);
	if (dfs(map, y, x + 1))
		return (1);
	if (dfs(map, y, x - 1))
		return (1);
	return (0);
}

void	check_path(t_map *map, t_game *game)
{
	if (player_position(map) == 1)
	{
		create_copy(map);
		dfs(map, map->player_y, map->player_x);
		if (map->exit_access == 1 && map->collectible == 0)
		{
			free_copy_map(map);
			return ;
		}
	}
	error_message("Error\nNo path exists from start to exit.\n");
	free_copy_map(map);
	free_map(map);
	free(game);
	exit(EXIT_FAILURE);
}
