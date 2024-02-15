/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:48:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/15 18:21:09 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_ext/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PIXELS 64

// SETTINGS COLORS
# define BLACK "\x1B[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1B[37m"
# define ORANGE "\x1B[38;2;255;128;0m"
# define ROSE "\x1B[38;2;255;151;203m"
# define LBLUE "\x1B[38;2;53;149;240m"
# define LGREEN "\x1B[38;2;17;245;120m"
# define GRAY "\x1B[38;2;176;174;174m"
# define CLEAR "\x1b[0m"

// SETTINGS BACKGROUND COLORS
# define BG_BLACK "\x1B[40m"
# define BG_RED "\x1B[41m"
# define BG_GREEN "\x1B[42m"
# define BG_YELLOW "\x1B[43m"
# define BG_BLUE "\x1B[44m"
# define BG_MAGENTA "\x1B[45m"
# define BG_CYAN "\x1B[46m"
# define BG_WHITE "\x1B[47m"
# define BG_ORANGE "\x1B[48;2;255;128;0m"
# define BG_LBLUE "\x1B[48;2;53;149;240m"
# define BG_LGREEN "\x1B[48;2;17;245;120m"
# define BG_GRAY "\x1B[48;2;176;174;174m"
# define BG_ROSE "\x1B[48;2;255;151;203m"

// SETTINGS KEYS
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define ON_DESTROY 17

// DEFINES
# define ERROR_LOADING_IMG "Error loading image\n"

typedef struct s_player
{
	int			posx;
	int			posy;
	int			steps;
}				t_player;

typedef struct s_sprites
{
	void		*img;
	char		*path;
	int			img_w;
	int			img_h;
}				t_sprites;

typedef struct s_map
{
	char		**map;
	int			map_w;
	int			map_h;
	int			main_char;
	int			exit;
	int			items;
	int			balls;
	t_player	player;
}				t_map;

// typedef struct s_vector_2D
// {
// 	float	x;
// 	float	y;
// }	t_vector_2D;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map_check;
	int			items;
	int			balls;
	int			posxmap;
	int			posymap;
	t_sprites	*ptr;
	t_player	player;
}				t_game;

// MAP FUNCTIONS
void			map_read(t_map *map, t_game *game, char *file);
char			*map_copy(t_map *map, int fd);

void			check_exit(t_game *game);
void			check_player(t_game *game);
void			sprite_exit(t_game *game, int i, int j);

void			move_player_up(t_game *game);
void			move_player_down(t_game *game);
void			move_player_left(t_game *game);
void			move_player_right(t_game *game);
void			sprite_creator(t_game *game, char *path, int i, int j);

// SPRITE FUNCTIONS
void			sprite_characters(t_map *map, t_game *game);

// MENSSAGE FUNCTIONS
void			show_error(char *str);

#endif