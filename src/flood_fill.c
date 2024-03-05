/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 03:45:00 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 01:46:37 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->player.instant_x = i;
				game->player.instant_y = j;
				game->player.previous_x = i;
				game->player.previous_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	get_exit_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.map[i][j] == 'E')
			{
				game->map.exit_x = i;
				game->map.exit_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static char	**map_duplicator(t_game *game, char **map)
{
	int	i;
	int	j;

	map = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!map)
	{
		free_array_of_strings(map);
		error_msg("Error: Memory allocation failed\n", 0);
		return (NULL);
	}
	map[game->map.rows] = NULL;
	i = -1;
	while (++i < game->map.rows)
	{
		map[i] = malloc(sizeof(char) * (game->map.cols + 1));
		if (!map[i])
		{
			free_array_of_strings(map);
			error_msg("Error: Memory allocation failed\n", 0);
			return (NULL);
		}
		j = 0;
		map_duplicator_extra(game, map, i, j);
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
	{
		free_array_of_strings(map);
		return (0);
	}
	free_array_of_strings(map);
	return (1);
}
