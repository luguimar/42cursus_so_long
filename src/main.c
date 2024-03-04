/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:18:37 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/04 02:15:46 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		return (error_msg("Error: Invalid number of arguments", 0));
	if (!check_extension(argv[1], ".ber"))
		return (error_msg("Error: Invalid file extension\n", 0));
	if (!check_map(argv[1], &game))
		return (error_msg("Error: Invalid map\n", 0));
	return (0);
}
