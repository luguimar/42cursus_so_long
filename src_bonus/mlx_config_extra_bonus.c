/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_config_extra_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:06:32 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 23:59:48 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	movement_announcer(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->player.moves);
	mlx_string_put(game->graphics.mlx, game->graphics.win, 10, \
		(game->map.rows * SIZE) + 18, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->graphics.mlx, game->graphics.win, 60, \
		(game->map.rows * SIZE) + 18, 0x00FFFFFF, moves);
	free(moves);
}

void	map_render_extra1(t_game *game, int i, int j)
{
	int	enemy_nr;

	enemy_nr = 0;
	while (game->graphics.enemies[enemy_nr].instant_x != j || \
	game->graphics.enemies[enemy_nr].instant_y != i)
		enemy_nr++;
	map_render_enemy(game, i, j, &enemy_nr);
}

void	map_rebuild_extra(t_game *game, int i, int j)
{
	int	enemy_nr;

	enemy_nr = 0;
	while (game->graphics.enemies[enemy_nr].instant_x != j || \
	game->graphics.enemies[enemy_nr].instant_y != i)
		enemy_nr++;
	if (game->map.map[game->graphics.enemies[enemy_nr].next_y] \
	[game->graphics.enemies[enemy_nr].next_x] == 'P')
	{
		ft_printf("You lost! You made %d moves!\n", game->player.moves);
		mlx_close(game);
	}
	game->map.map[game->graphics.enemies[enemy_nr].instant_y][game->graphics \
		.enemies[enemy_nr].instant_x] = '0';
	game->map.map[game->graphics.enemies[enemy_nr].next_y][game->graphics. \
		enemies[enemy_nr].next_x] = 'D';
	game->graphics.enemies[enemy_nr].instant_x = game->graphics.enemies \
		[enemy_nr].next_x;
	game->graphics.enemies[enemy_nr].instant_y = game->graphics.enemies \
		[enemy_nr].next_y;
}

void	map_rebuild(t_game *game)
{
	int	i;
	int	j;

	mlx_clear_window(game->graphics.mlx, game->graphics.win);
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.map[i][j] == 'D')
				map_rebuild_extra(game, i, j);
			j++;
		}
		i++;
	}
}
