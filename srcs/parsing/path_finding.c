/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:46:31 by nbelkace          #+#    #+#             */
/*   Updated: 2024/02/12 16:10:51 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	create_copy(t_map *map)
{
	int		x;
	int		j;

	map->map_copy = (char **)malloc((map->rows + 1) * sizeof(char *));
	if (map->map_copy == NULL)
		return ;
	x = 0;
	while (x < map->rows)
	{
		map->map_copy[x] = ft_strdup(map->map[x]);
		if (map->map_copy[x] == NULL)
		{
			j = 0;
			while (j < x)
			{
				free(map->map_copy[j]);
				j++;
			}
			free(map->map_copy);
			return ;
		}
		x++;
	}
	map->map_copy[x] = NULL;
}

static int    dfs(t_map *map, int y, int x)
{
    if (map->map_copy[y][x] == '1')
        return (0);
    if (map->map_copy[y][x] == 'C')
        temp->collect--;
    if (map->map_copy[y][x] == 'E')
    {
        map->acces_exit = 1;
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

// static void    exit_problem(char *str, t_map tmp, t_map *map)
// {
//     free_map(map);
//     handle_error(str, map, 1);
// }

// void    check_path(t_map *map)
// {
//     t_map    temp;
//     int        i;

//     temp.height = map->height;
//     temp.width = map->width;
//     temp.collect = map->collect;
//     temp.player_x = map->player_x;
//     temp.player_y = map->player_y;
//     temp.acces_exit = 0;
//     temp.map = (char **)ft_calloc((temp.height + 1), sizeof(char *));
//     if (!temp.map)
//         handle_error("Malloc problem during check path", map, 1);
//     temp.map[temp.height] = NULL;
//     i = -1;
//     while (++i < temp.height)
//     {
//         temp.map[i] = ft_strdup(map->map[i]);
//         if (!temp.map[i])
//             exit_problem("Malloc error", temp, map);
//     }
//     dfs(&temp, temp.player_y, temp.player_x);
//     if (!(temp.acces_exit == 1 && temp.collect == 0))
//         exit_problem("No valid path", temp, map);
//     free_temp(&temp);
// }