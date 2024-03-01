/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 05:12:31 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/01 05:13:11 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_player_position(t_game *game)
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

void	get_exit_position(t_game *game)
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
