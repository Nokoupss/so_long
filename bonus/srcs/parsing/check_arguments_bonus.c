/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:12:59 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/11 16:16:17 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	check_arguments(int argc)
{
	if (argc != 2)
	{
		error_message("Error\nWrong arguments");
		exit(EXIT_FAILURE);
	}
}
