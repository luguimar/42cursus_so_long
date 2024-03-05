/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:28:32 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/05 01:44:04 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"

# define SIZE	100
# define EMPTY		"../assets/img/empty.xpm"
# define ROCK		"../assets/img/rock.xpm"
# define PLAYER_L		"../assets/img/player_l.xpm"
# define PLAYER_R		"../assets/img/player_r.xpm"
# define GOLD		"../assets/img/gold.xpm"
# define EXIT		"../assets/img/exit.xpm"

typedef enum e_key
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307,
	UP = 65362,
	LEFT = 65361,
	DOWN = 65364,
	RIGHT = 65363,
}	t_key;

typedef struct s_player
{
	void	*img;
	int		instant_x;
	int		instant_y;
	int		previous_x;
	int		previous_y;
	int		height;
	int		width;
	int		direction;
	int		moves;
}	t_player;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}	t_sprite;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_graphics;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collectibles;
	int		exit_x;
	int		exit_y;
	int		player_nr;
	int		exit_nr;
}	t_map;

typedef struct s_game
{
	t_graphics	graphics;
	t_player	player;
	int			moves;
	int			winnign;
	t_map		map;
}	t_game;

int		error_msg(char *msg, int ret);
int		path_checker(t_game *game);
int		check_map(char *file, t_game *game);
int		map_filler_extra(char **line, int fd);
int		check_map_elements_extra(t_game *game, int i, int j);
void	map_duplicator_extra(t_game *game, char **map, int i, int j);

#endif
