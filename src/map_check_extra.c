/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:31:54 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 02:17:58 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_filler_extra(char **line, int fd)
{
	free(*line);
	close(fd);
	return (1);
}

int	check_map_elements_extra(t_game *game, int i, int j)
{
	if (game->map.map[i][j] != '1' && game->map.map[i][j] != '0' \
	&& game->map.map[i][j] != 'P' && game->map.map[i][j] != 'C' \
	&& game->map.map[i][j] != 'E')
	{
		free_array_of_strings(game->map.map);
		return (error_msg("Error\n Map has invalid elements\n", 0));
	}
	if (game->map.map[i][j] == 'P')
		game->map.player_nr++;
	if (game->map.map[i][j] == 'C')
		game->map.collectibles++;
	if (game->map.map[i][j] == 'E')
		game->map.exit_nr++;
	return (1);
}
