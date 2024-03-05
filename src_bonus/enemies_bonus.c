/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:07:20 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 13:15:48 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	enemy_movement_extra(t_game *game, int i, int j, int enemy_nr)
{
	int	count;

	count = game->graphics.count;
	if (count % 100 == 50)
	{
		if (game->map.map[i][j - 1] == '0' || game->map.map[i][j - 1] == 'P')
		{
			game->graphics.enemies[enemy_nr].next_x = j - 1;
			game->graphics.enemies[enemy_nr].direction = 1;
		}
	}
	else if (count % 100 == 75)
	{
		if (game->map.map[i - 1][j] == '0' || game->map.map[i - 1][j] == 'P')
			game->graphics.enemies[enemy_nr].next_y = i - 1;
	}
	else if (count >= 900)
		count = 0;
}

static void	enemy_movement(t_game *game, int i, int j, int enemy_nr)
{
	int	count;

	count = game->graphics.count;
	if (count % 100 == 0)
	{
		if (game->map.map[i][j + 1] == '0' || game->map.map[i][j + 1] == 'P')
		{
			game->graphics.enemies[enemy_nr].next_x = j + 1;
			game->graphics.enemies[enemy_nr].direction = 0;
		}
	}
	else if (count % 100 == 25)
	{
		if (game->map.map[i + 1][j] == '0' || game->map.map[i + 1][j] == 'P')
			game->graphics.enemies[enemy_nr].next_y = i + 1;
	}
	else
	{
		game->graphics.count = count;
		enemy_movement_extra(game, i, j, enemy_nr);
	}
}

static void	map_render_enemy_extra(t_game *game, int i, int j, int enemy_nr)
{
	int	count;

	count = game->graphics.count;
	if (count < 900)
	{
		game->graphics.enemies[enemy_nr].mouth = 0;
		if (game->graphics.enemies[enemy_nr].direction == 0)
			mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->graphics. \
			mouth_shut_r, j * SIZE, i * SIZE);
		else
			mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->graphics. \
			mouth_shut_l, j * SIZE, i * SIZE);
	}
	if (count >= 900)
		game->graphics.count = 0;
}

void	map_render_enemy(t_game *game, int i, int j, int enemy_nr)
{
	int	count;

	count = game->graphics.count;
	count++;
	game->graphics.count = count;
	if (count % 25 == 0)
		enemy_movement(game, i, j, enemy_nr);
	if (count < 450)
	{
		game->graphics.enemies[enemy_nr].mouth = 1;
		if (game->graphics.enemies[enemy_nr].direction == 0)
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
