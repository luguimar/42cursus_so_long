/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:28:32 by luguimar          #+#    #+#             */
/*   Updated: 2024/01/12 23:17:46 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"

typedef struct s_game
{
	int p_x;
	int p_y;
	void *mlx;
	void *win;

} t_game;

#endif
