/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:06:51 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/05 17:58:33 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	error_message(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (write(2, str, len) == -1)
	{
		write(2, "Error\n, la j'avoue t'es fort.\n", 29);
		exit(EXIT_FAILURE);
	}
}

int	get_len_map(int fd, t_game *game)
{
	size_t	len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		len++;
	}
	if (len < 3)
	{
		error_message("Error\nMap too small.\n");
		free_map(game->map);
		free(game);
		exit(EXIT_FAILURE);
	}
	return (len);
}

int	ft_strlen_backslash_n(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	check_all_error(t_map *map, char *file, t_game *game)
{
	check_file_extension(file, game);
	check_len_map(map, game);
	check_rectangle(map, game);
	check_map_outline(map, game);
	if (check_map_characters(map) == 0)
	{
		error_message("Error\nInvalid characters in the map.\n");
		free_map(map);
		free(game);
		exit(EXIT_FAILURE);
	}
}

void	check_len_map(t_map *map, t_game *game)
{
	if (map == NULL)
		return ;
	if (map->rows * 32 > 1080 || map->cols * 32 > 1980)
	{
		error_message("Error\nMap too big\n");
		free_map(map);
		free(game);
		exit(EXIT_FAILURE);
	}
	return ;
}
