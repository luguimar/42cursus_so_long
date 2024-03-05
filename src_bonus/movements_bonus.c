/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:05:46 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 21:22:17 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	move_extra(int x, int y, t_game *game)
{
	if (game->map.map[x][y] == 'D')
	{
		ft_printf("You lost! You made %d moves!\n", game->player.moves);
		mlx_close(game);
	}
}

static void	move(int x, int y, t_game *game)
{
	if (game->map.map[x][y] != '1')
	{
		if (game->map.map[x][y] == 'C')
		{
			game->map.collectibles--;
			game->map.map[x][y] = 'P';
		}
		if (game->map.map[x][y] == 'E' && game->map.collectibles == 0)
		{
			ft_printf("You won! You made %d moves!\n", game->player.moves);
			mlx_close(game);
		}
		move_extra(x, y, game);
		if (game->player.instant_x == game->map.exit_x && game->player. \
		instant_y == game->map.exit_y)
			game->map.map[game->player.instant_x][game->player.instant_y] = 'E';
		else
			game->map.map[game->player.instant_x][game->player.instant_y] = '0';
		game->player.instant_x = x;
		game->player.instant_y = y;
		game->map.map[x][y] = 'P';
		game->player.moves++;
		ft_printf("Moves: %d\n", game->player.moves);
	}
	map_render(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		mlx_close(game);
	else if (keycode == W || keycode == UP)
		move(game->player.instant_x - 1, game->player.instant_y, game);
	else if (keycode == A || keycode == LEFT)
	{
		game->player.direction = 0;
		move(game->player.instant_x, game->player.instant_y - 1, game);
	}
	else if (keycode == S || keycode == DOWN)
		move(game->player.instant_x + 1, game->player.instant_y, game);
	else if (keycode == D || keycode == RIGHT)
	{
		game->player.direction = 1;
		move(game->player.instant_x, game->player.instant_y + 1, game);
	}
	return (0);
}
