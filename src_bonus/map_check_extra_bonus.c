/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_extra_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:31:54 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 13:07:07 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	set_enemy_coordinates(t_game *game, int enemy_nr)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'D')
			{
				if (count == enemy_nr)
				{
					game->graphics.enemies[enemy_nr].instant_x = j;
					game->graphics.enemies[enemy_nr].instant_y = i;
					game->graphics.enemies[enemy_nr].next_x = j;
					game->graphics.enemies[enemy_nr].next_y = i;
					return ;
				}
				count++;
			}
		}
	}
}

int	check_map_aux(t_game *game)
{
	int	i;

	i = 0;
	game->graphics.enemies = malloc(sizeof(t_enemy) * game->map.enemies);
	if (!game->graphics.enemies)
	{
		free_array_of_strings(game->map.map);
		error_msg("Error\nMalloc failed\n", 0);
		return (0);
	}
	while (i < game->map.enemies)
	{
		set_enemy_coordinates(game, i);
		game->graphics.enemies[i].direction = 0;
		game->graphics.enemies[i].mouth = 0;
		game->graphics.count = 0;
		i++;
	}
	return (1);
}

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
	&& game->map.map[i][j] != 'E' && game->map.map[i][j] != 'D')
	{
		free_array_of_strings(game->map.map);
		return (error_msg("Error\n Map has invalid elements\n", 0));
	}
	if (game->map.map[i][j] == 'P')
		game->map.player_nr++;
	if (game->map.map[i][j] == 'C')
		game->map.collectibles++;
	if (game->map.map[i][j] == 'D')
		game->map.enemies++;
	if (game->map.map[i][j] == 'E')
		game->map.exit_nr++;
	return (1);
}
