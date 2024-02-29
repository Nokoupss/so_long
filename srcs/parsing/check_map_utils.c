/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:06:51 by nbelkace          #+#    #+#             */
/*   Updated: 2024/02/29 16:14:42 by nbelkace         ###   ########.fr       */
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

int	destroy(t_game *game)
{
	if (game->coin)
		mlx_destroy_image(game->mlx_ptr, game->coin);
	if (game->doorclosed)
		mlx_destroy_image(game->mlx_ptr, game->doorclosed);
	if (game->dooropen)
		mlx_destroy_image(game->mlx_ptr, game->dooropen);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game->map);
	free(game->map);
	exit(EXIT_FAILURE);
}
