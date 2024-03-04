/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:31:46 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/04 15:52:43 by nbelkace         ###   ########.fr       */
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
	if (argc != 2)
	{
		error_message("Error\nWrong arguments");
		exit(EXIT_FAILURE);
	}
	fd = open_file(argv[1]);
	game->map = create_map(fd, argv[1]);
	check_all_error(game->map, argv[1]);
	check_path(game->map);
	window_display(game);
	init_sprite(game);
	render_all(game);
	mlx_loop(game->mlx_ptr);
	close(fd);
	free_all_memory(game);
	return (0);
}
