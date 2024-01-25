/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:28:32 by luguimar          #+#    #+#             */
/*   Updated: 2024/01/24 21:15:53 by luguimar         ###   ########.fr       */
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
	int		height;
	int		width;
	int		instant_x;
	int		instant_y;
	int		previous_x;
	int		previous_y;
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
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	t_graphics	graphics;
	int			map_width;
	int			map_height;
	int			rows;
	int			cols;
	int			collectibles;
	int			moves;
	int			winnign;
	int			lose;
	t_player	player;
	char		**map;
}	t_game;

/*
typedef struct s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
}					t_graphics;

typedef struct s_player
{
	void	*img;
	int		height;
	int		width;
	int		instant_x;
	int		instant_y;
	int		previous_x;
	int		previous_y;
	int		direction;
	int		moves;
}					t_player;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}					t_sprite;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collectibles;
}					t_map;

typedef struct s_game
{
	t_graphics	*graphics;
	t_player	*player;
	t_sprite	*empty;
	t_sprite	*rock;
	t_sprite	*gold;
	t_sprite	*exit;
	t_map		*map;
	int			win;
	int			lose;
}					t_game;
*/

int	ft_error(char *str, int ret);

#endif
