/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:28:40 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/11 16:32:29 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	collectible_check(t_game *game)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (game->map->map[y] != NULL)
	{
		x = 0;
		while (game->map->map[y][x] != '\0')
		{
			if (game->map->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	if (count == 0)
		return (1);
	return (0);
}

void	print_move(t_game *game)
{
	char	*moves;

	moves = ft_itoa_base(game->map->count, "0123456789");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 0, WIN_HEIGHT, \
	0xffffff, "Moves :");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 42, WIN_HEIGHT, \
	0xffffff, moves);
	free(moves);
}
