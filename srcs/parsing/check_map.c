/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:23:28 by nbelkace          #+#    #+#             */
/*   Updated: 2024/02/08 17:34:48 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_file_extension(char *file)
{
	char	*extension;
	size_t	len;

	extension = ft_strrchr(file, '.');
	if (extension == NULL)
	{
		error_message("Error\nNo file extension.\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(extension);
	if (len < 4)
		len = 4;
	if (ft_strncmp(extension, ".ber", len) != 0)
	{
		error_message("Error\nWrong file extension.\n");
		exit(EXIT_FAILURE);
	}
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		error_message("Error\nReading the file.\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	check_rectangle(t_map *map)
{
	int	expected_length;
	int	x;
	int	y;

	expected_length = ft_strlen_backslash_n(map->map[0]);
	map->cols = expected_length;
	x = 0;
	y = 0;
	while (x < map->rows)
	{
		if (ft_strlen_backslash_n(map->map[x]) != expected_length)
		{
			error_message("Error\nMap is not a rectangle.\n");
			exit(EXIT_FAILURE);
		}
		x++;
		y++;
	}
}

int	check_map_characters(t_map *map)
{
	int		x;
	int		y;
	char	*row_content;

	x = -1;
	while (++x < map->rows)
	{
		y = 0;
		row_content = map->map[x];
		while (row_content[y] && row_content[y] != '\n')
		{
			if (row_content[y] == 'P')
				map->player++;
			else if (row_content[y] == 'E')
				map->exit++;
			else if (row_content[y] == 'C')
				map->collectible++;
			else if (row_content[y] != '1' && row_content[y] != '0')
				return (0);
		y++;
		}
	}
	if (map->player == 1 && map->exit == 1 && map->collectible >= 1)
		return (1);
	return (0);
}

void	check_map_outline(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->cols)
	{
		if (map->map[0][x] != '1' || map->map[map->rows - 1][x] != '1')
		{
			error_message("Error\nMap outline is not made of 1.\n");
			exit(EXIT_FAILURE);
		}
		x++;
	}
	y = 0;
	while (y < map->rows)
	{
		if (map->map[y][0] != '1' || map->map[y][map->cols - 1] != '1')
		{
			error_message("Error\nMap outline is not made of 1.\n");
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

void	check_all_error(t_map *map, char *file)
{
	check_file_extension(file);
	check_rectangle(map);
	check_map_outline(map);
	if (check_map_characters(map) == 0)
	{
		error_message("Error\nInvalid characters in the map.\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("all good les reufs\n");
}
