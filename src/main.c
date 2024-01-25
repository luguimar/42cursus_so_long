/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:18:37 by luguimar          #+#    #+#             */
/*   Updated: 2024/01/24 21:15:48 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_check_extension(char *str, char *ext)
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

int	ft_error(char *str, int ret)
{
	ft_putstr_fd(str, 2);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_error("Error\nInvalid number of arguments\n", 0));
	if (!ft_check_extension(argv[1], ".ber"))
		return (ft_error("Error\nInvalid file extension\n", 0));
	if (!ft_check_map(argv[1]))
		return (ft_error("Error\nInvalid map\n", 0));
	return (0);
}
