/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:31:46 by nbelkace          #+#    #+#             */
/*   Updated: 2024/02/09 18:46:37 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	size_t	i;

	i = 0;
	if (argc != 2)
	{
		error_message("Error\nWrong arguments");
		exit(EXIT_FAILURE);
	}
	fd = open_file(argv[1]);
	map = create_map(fd, argv[1]);
	check_all_error(map, argv[1]);
	create_copy(map);
	while (map->map[i])
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
	close(fd);
	free_map(map);
	return (0);
}
