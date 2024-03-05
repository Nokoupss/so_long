/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:13:40 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/05 18:07:53 by nbelkace         ###   ########.fr       */
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
	map->count = 0;
	return (map);
}

void	create_map(int fd, char *file, t_game *game)
{
	size_t		len;
	size_t		x;
	int			fd2;

	game->map = init_map();
	len = get_len_map(fd, game);
	x = 0;
	game->map->rows = len;
	game->map->map = (char **)malloc(sizeof(char *) * (len + 1));
	if (game->map->map == NULL)
		return ;
	fd2 = open_file(file, game);
	game->map->map[x] = get_next_line(fd2);
	while (len > 0)
	{
		x++;
		game->map->map[x] = get_next_line(fd2);
		len--;
	}
	close(fd2);
}
