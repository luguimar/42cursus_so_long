/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:07:20 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 22:53:47 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	enemy_movement_extra(t_game *game, int i, int j, int *enemy_nr)
{
	int	nr;

	nr = game->graphics.random_nr;
	if (nr == 2)
	{
		if (game->map.map[i][j - 1] == '0' || game->map.map[i][j - 1] == 'P')
		{
			game->graphics.enemies[*enemy_nr].next_x = j - 1;
			game->graphics.enemies[*enemy_nr].direction = 1;
		}
	}
	else if (nr == 3)
	{
		if (game->map.map[i - 1][j] == '0' || game->map.map[i - 1][j] == 'P')
			game->graphics.enemies[*enemy_nr].next_y = i - 1;
	}
}

static void	enemy_movement(t_game *game, int i, int j, int *enemy_nr)
{
	int	nr;

	nr = rand() % 4;
	game->graphics.random_nr = nr;
	if (nr == 0)
	{
		if (game->map.map[i][j + 1] == '0' || game->map.map[i][j + 1] == 'P')
		{
			game->graphics.enemies[*enemy_nr].next_x = j + 1;
			game->graphics.enemies[*enemy_nr].direction = 0;
		}
	}
	else if (nr == 1)
	{
		if (game->map.map[i + 1][j] == '0' || game->map.map[i + 1][j] == 'P')
			game->graphics.enemies[*enemy_nr].next_y = i + 1;
	}
	else
		enemy_movement_extra(game, i, j, enemy_nr);
}

static void	map_render_enemy_extra(t_game *game, int i, int j, int *enemy_nr)
{
	int	count;

	count = game->graphics.count;
	if (count < 500)
	{
		game->graphics.enemies[*enemy_nr].mouth = 0;
		if (game->graphics.enemies[*enemy_nr].direction == 0)
			mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->graphics. \
			mouth_shut_r, j * SIZE, i * SIZE);
		else
			mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->graphics. \
			mouth_shut_l, j * SIZE, i * SIZE);
	}
	if (count >= 500)
		game->graphics.count = 0;
}

void	map_render_enemy(t_game *game, int i, int j, int *enemy_nr)
{
	int	count;

	count = game->graphics.count;
	count++;
	game->graphics.count = count;
	if (count % 125 == 0)
		enemy_movement(game, i, j, enemy_nr);
	if (count < 250)
	{
		game->graphics.enemies[*enemy_nr].mouth = 1;
		if (game->graphics.enemies[*enemy_nr].direction == 0)
			mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->graphics. \
			mouth_open_r, j * SIZE, i * SIZE);
		else
			mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->graphics. \
			mouth_open_l, j * SIZE, i * SIZE);
	}
	else
		map_render_enemy_extra(game, i, j, enemy_nr);
}
