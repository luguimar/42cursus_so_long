/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:18:37 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 07:48:01 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	error_msg(char *msg, int ret)
{
	ft_putstr_fd(msg, 2);
	return (ret);
}

void	*error_free_msg(char *msg, int flag, t_game *game, char **map)
{
	int	*ret;

	(void)game;
	if (msg)
		ft_putstr_fd(msg, 2);
	free_array_of_strings(map);
	if (flag == 2)
		return (NULL);
	else
	{
		ret = &flag;
		return (ret);
	}
}

static int	check_extension(char *str, char *ext)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (ext[j])
		j++;
	if (i < j)
		return (0);
	while (j >= 0)
	{
		if (str[i] != ext[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_msg("Error\n Invalid number of arguments", 0));
	if (!check_extension(argv[1], ".ber"))
		return (error_msg("Error\n Invalid file extension\n", 0));
	if (!check_map(argv[1], &game))
		return (error_msg("Error\n Invalid map\n", 0));
	game.player.moves = 0;
	mlx_start(&game);
	return (0);
}
