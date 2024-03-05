/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ckeck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:15:48 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 02:17:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_map_elements(t_game *game, int i, int j)
{
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (i == 0 || i == game->map.rows - 1 || j == 0 \
			|| j == game->map.cols - 1)
			{
				if (game->map.map[i][j] != '1')
				{
					free_array_of_strings(game->map.map);
					return (error_msg("Error\n Map is not closed\n", 0));
				}
			}
			if (!check_map_elements_extra(game, i, j))
				return (0);
		}
	}
	if (game->map.player_nr != 1 || game->map.exit_nr != 1)
	{
		free_array_of_strings(game->map.map);
		return (error_msg("Error\n Map has invalid number of players or exits\n" \
		, 0));
	}
	return (1);
}

static int	map_filler(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	game->map.map = malloc(sizeof(char *) * (game->map.rows + 1));
	game->map.map[game->map.rows] = NULL;
	if (!game->map.map)
		return (error_msg("Error\n Memory allocation failed\n", 0));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		game->map.map[++i] = ft_substr(line, 0, game->map.cols);
		if (!game->map.map[i])
		{
			free_array_of_strings(game->map.map);
			return (error_msg("Error\n Memory allocation failed\n", 0));
		}
		free(line);
		line = get_next_line(fd);
	}
	return (map_filler_extra(&line, fd));
}

static int	check_rectangle(int fd, char **line, t_game *game)
{
	int	rectangle;

	rectangle = 1;
	game->map.rows = 0;
	while (*line)
	{
		if (((*line)[ft_strlen(*line) - 1] != '\n' && (int) ft_strlen(*line) \
		!= game->map.cols) || ((*line)[ft_strlen(*line) - 1] == '\n' \
		&& (int) ft_strlen(*line) != game->map.cols + 1))
			rectangle = 0;
		game->map.rows++;
		free(*line);
		*line = get_next_line(fd);
	}
	free(*line);
	close(fd);
	if (rectangle == 0)
		return (error_msg("Error\n Map is not a rectangle\n", 0));
	return (1);
}

static int	check_map_extra(char *file, int fd, char **line, t_game *game)
{
	if (!check_rectangle(fd, line, game))
		return (0);
	if (game->map.rows < 3 || game->map.cols < 3)
		return (error_msg("Error\n Map is too small\n", 0));
	if (!map_filler(file, game))
		return (0);
	game->map.collectibles = 0;
	game->map.exit_nr = 0;
	game->map.player_nr = 0;
	if (!check_map_elements(game, -1, -1))
		return (0);
	if (game->map.collectibles == 0)
	{
		free_array_of_strings(game->map.map);
		return (error_msg("Error\n Map has no collectibles\n", 0));
	}
	if (!path_checker(game))
	{
		free_array_of_strings(game->map.map);
		return (error_msg \
			("Error\n Exit and/or not all collectibles are reachable\n", 0));
	}
	return (1);
}

int	check_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*aux;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (error_msg("Error\n Map is empty\n", 0));
	if (line[ft_strlen(line) - 1] == '\n')
	{
		aux = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
		if (!aux)
			return (error_msg("Error\n Memory allocation failed\n", 0));
		line = aux;
		game->map.cols = ft_strlen(line);
	}
	else
	{
		free(line);
		return (error_msg("Error\n Map only has one row\n", 0));
	}
	return (check_map_extra(file, fd, &line, game));
}
