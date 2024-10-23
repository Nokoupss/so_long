/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:31:46 by nbelkace          #+#    #+#             */
/*   Updated: 2024/10/23 11:05:33 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

void	hook(t_game *game)
{
	mlx_key_hook(game->mlx_win, escape_input, game);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, movement_input, game);
	mlx_hook(game->mlx_win, DestroyNotify, 0, free_all_memory, game);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		keysym;

	keysym = 0;
	check_arguments(argc);
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		return (0);
	game->map = NULL;
	game->fd = open_file(argv[1], game);
	if (game->fd == -1)
		free(game);
	if (game->fd == -1)
		exit(EXIT_FAILURE);
	create_map(argv[1], game);
	check_all_error(game->map, argv[1], game);
	check_path(game->map, game);
	init_sprite(game);
	if (window_display(game) == 0)
		free_all_memory(game);
	create_sprite(game);
	hook(game);
	render_all(game, keysym);
	mlx_loop(game->mlx_ptr);
	free_all_memory(game);
}
