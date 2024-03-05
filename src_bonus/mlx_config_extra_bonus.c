/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_config_extra_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:06:32 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 12:04:05 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	map_rebuild(t_game *game)
{
	int	i;

	mlx_clear_window(game->graphics.mlx, game->graphics.win);
	i = 0;
	while (i < game->map.enemies)
	{
		if (game->map.map[game->graphics.enemies[i].next_y] \
		[game->graphics.enemies[i].next_x] == 'P')
		{
			ft_printf("You lost!\n");
			mlx_close(game);
		}
		game->map.map[game->graphics.enemies[i].instant_y][game->graphics \
			.enemies[i].instant_x] = '0';
		game->map.map[game->graphics.enemies[i].next_y][game->graphics. \
			enemies[i].next_x] = 'D';
		game->graphics.enemies[i].instant_x = game->graphics.enemies[i].next_x;
		game->graphics.enemies[i].instant_y = game->graphics.enemies[i].next_y;
		i++;
	}
}
