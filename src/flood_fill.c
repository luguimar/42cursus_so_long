/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 03:45:00 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/04 02:14:54 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**map_duplicator(t_game *game, char **map)
{
	int	i;
	int	j;

	map = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!map)
		return ((char **)error_free_msg("Error: Memory allocation failed\n", 2, \
		game, 0));
	map[game->map.rows] = NULL;
	i = 0;
	while (i < game->map.rows)
	{
		map[i] = malloc(sizeof(char) * (game->map.cols + 1));
		if (!map[i])
			return ((char **)error_free_msg("Error: Memory allocation \
			failed\n", 2, game, map));
		map[i][game->map.cols] = '\0';
		j = 0;
		while (j < game->map.cols)
		{
			map[i][j] = game->map.map[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

static int	flood_fill(t_game *game, int x, int y, char **map)
{
	static int	collectibles;
	static int	exit;

	if (x < 0 || y < 0 || x >= game->map.rows || y >= game->map.cols)
		return (0);
	if (map[x][y] == '1')
		return (0);
	if (map[x][y] == 'C')
		collectibles++;
	else if (map[x][y] == 'E')
		exit++;
	map[x][y] = '1';
	flood_fill(game, x + 1, y, map);
	flood_fill(game, x - 1, y, map);
	flood_fill(game, x, y + 1, map);
	flood_fill(game, x, y - 1, map);
	if (collectibles != game->map.collectibles || exit != 1)
		return (0);
	return (1);
}

int	path_checker(t_game *game)
{
	char		**map;

	map = NULL;
	map = map_duplicator(game, map);
	if (!map)
		return (0);
	get_player_position(game);
	get_exit_position(game);
	if (!flood_fill(game, game->player.instant_x, game->player.instant_y, map))
		return (*(int *)error_free_msg(0, 0, game, map));
	free_array_of_strings(map);
	return (1);
}
