/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:31:46 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/05 18:22:11 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	size_t	i;
	int		fd;

	i = 0;
	game = (t_game *)malloc(sizeof(t_game));
	game->map = NULL;
	if (argc != 2)
	{
		error_message("Error\nWrong arguments");
		exit(EXIT_FAILURE);
	}
	fd = open_file(argv[1], game);
	create_map(fd, argv[1], game);
	check_all_error(game->map, argv[1], game);
	check_path(game->map);
	window_display(game);
	init_sprite(game);
	mlx_key_hook(game->mlx_win, escape_input, game);
	mlx_key_hook(game->mlx_win, movement_input, game);
	render_all(game);
	mlx_loop(game->mlx_ptr);
	close(fd);
	free_all_memory(game);
	return (0);
}
