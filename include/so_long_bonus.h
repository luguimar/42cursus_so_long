/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:28:32 by luguimar          #+#    #+#             */
/*   Updated: 2024/03/06 00:01:47 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <math.h>
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
	void	*img_l;
	void	*img_r;
	int		instant_x;
	int		instant_y;
	int		direction;
	int		moves;
}	t_player;

typedef struct s_enemy
{
	int			instant_x;
	int			instant_y;
	int			next_x;
	int			next_y;
	int			direction;
	int			mouth;
}	t_enemy;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*empty;
	void	*rock;
	void	*gold;
	void	*exit;
	void	*mouth_shut_l;
	void	*mouth_shut_r;
	void	*mouth_open_l;
	void	*mouth_open_r;
	int		count;
	int		random_nr;
	t_enemy	*enemies;
}	t_graphics;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collectibles;
	int		enemies;
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
void	mlx_start(t_game *game);
int		mlx_close(t_game *game);
int		map_render(t_game *game);
int		key_hook(int keycode, t_game *game);
void	map_render_enemy(t_game *game, int i, int j, int *enemy_nr);
int		check_map_aux(t_game *game);
void	map_rebuild(t_game *game);
void	map_render_extra1(t_game *game, int i, int j);
void	movement_announcer(t_game *game);

#endif
