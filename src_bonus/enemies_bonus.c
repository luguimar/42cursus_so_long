/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:07:20 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 20:34:39 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	enemy_movement_extra(t_game *game, int i, int j, int enemy_nr)
{
	int	count;

	count = game->graphics.count;
	if ((count + game->player.instant_x) * game->player.instant_y % 4 == 2)
	{
		if (game->map.map[i][j - 1] == '0' || game->map.map[i][j - 1] == 'P')
		{
			game->graphics.enemies[enemy_nr].next_x = j - 1;
			game->graphics.enemies[enemy_nr].direction = 1;
		}
	}
	else if ((count + game->player.instant_x) * game->player.instant_y % 4 == 3)
	{
		if (game->map.map[i - 1][j] == '0' || game->map.map[i - 1][j] == 'P')
			game->graphics.enemies[enemy_nr].next_y = i - 1;
	}
}

static void	enemy_movement(t_game *game, int i, int j, int enemy_nr)
{
	int	count;

	count = game->graphics.count;
	if ((count + game->player.instant_x) * game->player.instant_y % 4 == 0)
	{
		if (game->map.map[i][j + 1] == '0' || game->map.map[i][j + 1] == 'P')
		{
			game->graphics.enemies[enemy_nr].next_x = j + 1;
			game->graphics.enemies[enemy_nr].direction = 0;
		}
	}
	else if ((count + game->player.instant_x) * game->player.instant_y % 4 == 1)
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
	if (count < 1000)
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
	if (count >= 1000)
		game->graphics.count = 0;
}

// This following function is called to ensure that the enemies in a different
// odd/even situation will also move. This is done by checking if the enemy_nr
// is greater than the number of enemies in the map. If it is, it will be
// decremented, otherwise, it will be incremented. This way, the enemies will
// with +1 or -1 index will also move and in a different way so that the
// movement of the enemies is not synchronized.

void	map_odd_enemy_movement(t_game *game, int i, int j, int enemy_nr)
{
	game->graphics.count += 250;
	if (enemy_nr >= game->map.enemies)
		enemy_nr--;
	else
		enemy_nr++;
	if (game->graphics.count % 250 == 0)
		enemy_movement(game, i, j, enemy_nr);
	game->graphics.count -= 250;
}

void	map_render_enemy(t_game *game, int i, int j, int enemy_nr)
{
	int	count;

	count = game->graphics.count;
	count++;
	game->graphics.count = count;
	if (count % 250 == 0)
		enemy_movement(game, i, j, enemy_nr);
	if (count < 500)
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
