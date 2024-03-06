/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_config_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:07:31 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/06 00:00:19 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	mlx_close(t_game *game)
{
	mlx_destroy_image(game->graphics.mlx, game->graphics.empty);
	mlx_destroy_image(game->graphics.mlx, game->graphics.rock);
	mlx_destroy_image(game->graphics.mlx, game->player.img_l);
	mlx_destroy_image(game->graphics.mlx, game->player.img_r);
	mlx_destroy_image(game->graphics.mlx, game->graphics.gold);
	mlx_destroy_image(game->graphics.mlx, game->graphics.exit);
	mlx_destroy_window(game->graphics.mlx, game->graphics.win);
	mlx_destroy_display(game->graphics.mlx);
	free(game->graphics.mlx);
	free_array_of_strings(game->map.map);
	exit(0);
	return (0);
}

static void	map_render_extra(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == 'C')
		mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->graphics.gold, j * SIZE, i * SIZE);
	else if (game->map.map[i][j] == 'E')
		mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->graphics.exit, j * SIZE, i * SIZE);
	else if (game->map.map[i][j] == 'P')
	{
		if (game->player.direction == 0)
			mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->player.img_l, j * SIZE, i * SIZE);
		else if (game->player.direction == 1)
			mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->player.img_r, j * SIZE, i * SIZE);
		else
			mlx_put_image_to_window(game->graphics.mlx, \
			game->graphics.win, game->player.img_r, j * SIZE, i * SIZE);
	}
	else if (game->map.map[i][j] == '0')
		mlx_put_image_to_window(game->graphics.mlx, \
		game->graphics.win, game->graphics.empty, j * SIZE, i * SIZE);
	else if (game->map.map[i][j] == 'D')
		map_render_extra1(game, i, j);
}

int	map_render(t_game *game)
{
	static int	frames;
	int			i;
	int			j;

	if (++frames < 100)
		return (1);
	frames = 0;
	map_rebuild(game);
	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.map[i][j] == '1')
				mlx_put_image_to_window(game->graphics.mlx, \
				game->graphics.win, game->graphics.rock, j * SIZE, i * SIZE);
			else
				map_render_extra(game, i, j);
		}
	}
	movement_announcer(game);
	return (1);
}

static void	set_mlx_images(t_game *game)
{
	int	i;

	i = SIZE;
	game->graphics.empty = mlx_xpm_file_to_image(game->graphics.mlx, \
		"assets/img/empty.xpm", &i, &i);
	game->graphics.rock = mlx_xpm_file_to_image(game->graphics.mlx, \
		"assets/img/rock.xpm", &i, &i);
	game->player.img_l = mlx_xpm_file_to_image(game->graphics.mlx, \
		"assets/img/player_l.xpm", &i, &i);
	game->player.img_r = mlx_xpm_file_to_image(game->graphics.mlx, \
		"assets/img/player_r.xpm", &i, &i);
	game->graphics.gold = mlx_xpm_file_to_image(game->graphics.mlx, \
		"assets/img/gold.xpm", &i, &i);
	game->graphics.exit = mlx_xpm_file_to_image(game->graphics.mlx, \
		"assets/img/exit.xpm", &i, &i);
	game->graphics.mouth_shut_l = mlx_xpm_file_to_image(game->graphics \
		.mlx, "assets/img/enemy_cl.xpm", &i, &i);
	game->graphics.mouth_shut_r = mlx_xpm_file_to_image(game->graphics \
		.mlx, "assets/img/enemy_cr.xpm", &i, &i);
	game->graphics.mouth_open_l = mlx_xpm_file_to_image(game->graphics \
		.mlx, "assets/img/enemy_ol.xpm", &i, &i);
	game->graphics.mouth_open_r = mlx_xpm_file_to_image(game->graphics \
		.mlx, "assets/img/enemy_or.xpm", &i, &i);
}

void	mlx_start(t_game *game)
{
	game->graphics.mlx = mlx_init();
	if (!game->graphics.mlx)
	{
		ft_putstr_fd("Error\nmlx_init failed\n", 2);
		exit(1);
	}
	game->graphics.win = mlx_new_window(game->graphics.mlx, game->map.cols \
	* SIZE, (game->map.rows * SIZE) + 25, "so_long");
	if (!game->graphics.win)
	{
		mlx_destroy_display(game->graphics.mlx);
		ft_putstr_fd("Error\nmlx_new_window failed\n", 2);
		exit(1);
	}
	game->player.direction = 1;
	set_mlx_images(game);
	map_render(game);
	mlx_hook(game->graphics.win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->graphics.win, 17, 0, mlx_close, game);
	mlx_loop_hook(game->graphics.mlx, map_render, game);
	mlx_loop(game->graphics.mlx);
}
