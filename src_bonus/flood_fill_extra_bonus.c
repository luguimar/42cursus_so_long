/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_extra_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:42:46 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 07:47:52 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	map_duplicator_extra(t_game *game, char **map, int i, int j)
{
	map[i][game->map.cols] = '\0';
	while (j < game->map.cols)
	{
		map[i][j] = game->map.map[i][j];
		j++;
	}
}
