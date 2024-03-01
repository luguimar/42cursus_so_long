/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:18:37 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/01 05:24:58 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	error_msg(char *str, int ret)
{
	ft_putstr_fd(str, 2);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_msg("Error: Invalid number of arguments\n", 0));
	if (!check_extension(argv[1], ".ber"))
		return (error_msg("Error: Invalid file extension\n", 0));
	if (!check_map(argv[1], &game))
		return (error_msg("Error: Invalid map\n", 0));
	return (0);
}
