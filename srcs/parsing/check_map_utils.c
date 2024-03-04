/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:06:51 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/04 15:49:37 by nbelkace         ###   ########.fr       */
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

int	get_len_map(int fd)
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
		error_message("Error\nMap too small.");
		exit(EXIT_FAILURE);
	}
	return (len);
}

int	ft_strlen_backslash_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
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
}
