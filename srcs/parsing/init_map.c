/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:13:40 by nbelkace          #+#    #+#             */
/*   Updated: 2024/02/29 13:16:46 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (MALLOC_ERROR);
	map->map = NULL;
	map->rows = 0;
	map->cols = 0;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
	map->exit_access = 0;
	return (map);
}

t_map	*create_map(int fd, char *file)
{
	t_map		*map;
	size_t		len;
	size_t		x;
	int			fd2;

	map = init_map();
	len = get_len_map(fd);
	x = 0;
	map->rows = len;
	map->map = (char **)malloc(sizeof(char *) * (len + 1));
	if (map->map == NULL)
		return (MALLOC_ERROR);
	fd2 = open_file(file);
	map->map[x] = get_next_line(fd2);
	while (len > 0)
	{
		x++;
		map->map[x] = get_next_line(fd2);
		len--;
	}
	close(fd2);
	return (map);
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

void	free_copy_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map_copy[i])
	{
		free(map->map_copy[i]);
		i++;
	}
	free(map->map_copy);
}
