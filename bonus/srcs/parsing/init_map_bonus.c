/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:13:40 by nbelkace          #+#    #+#             */
/*   Updated: 2024/10/21 14:15:09 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
	map->ennemy = 0;
	map->exit_access = 0;
	map->count = 0;
	return (map);
}

void	create_map(char *file, t_game *game)
{
	size_t		len;
	size_t		x;
	int			fd2;

	game->map = init_map();
	if (game->map == NULL)
		return ;
	len = get_len_map(game);
	x = 0;
	game->map->rows = len;
	game->map->map = (char **)malloc(sizeof(char *) * (len + 1));
	if (game->map->map == NULL)
		return ;
	fd2 = open_file(file, game);
	if (fd2 == -1)
	{
		free(game->map);
		free(game->map->map);
		exit(EXIT_FAILURE);
	}
	game->map->map[x] = get_next_line(fd2);
	while ((len--) > 0)
		game->map->map[++x] = get_next_line(fd2);
	close(fd2);
	close(game->fd);
}
