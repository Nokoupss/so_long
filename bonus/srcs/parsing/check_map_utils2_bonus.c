/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:21:43 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/11 16:21:54 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_map_characters_utils(t_map *map, char c)
{
	if (c == 'P')
		map->player++;
	else if (c == 'E')
		map->exit++;
	else if (c == 'C')
		map->collectible++;
	else if (c == 'S')
		map->ennemy++;
	else if (c != '1' && c != '0')
		return (0);
	return (1);
}
