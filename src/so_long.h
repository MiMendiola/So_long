/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:48:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/18 22:00:24 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_ext/libft.h"
# include "../mlx/mlx.h"
# include "./utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int			first_animation;
	int			evolution;
}				t_flags;

typedef struct s_player
{
	int			posx;
	int			posy;
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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map_check;
	int			items;
	int			balls;
	int			steps;
	int			exitX;
	int			exitY;
	int			frames;
	t_sprites	*image;
	t_player	player;
	t_flags		flags;
}				t_game;

// MAP FUNCTIONS
void			map_read(t_map *map, t_game *game, char *file);
char			*map_copy(t_map *map, int fd);
void			check_player(t_game *game);

// MOVEMENTS FUNCTIONS
void			movement_goku_base(t_game *game, int posx, int posy);
void			move_player_up(t_game *game);
void			move_player_down(t_game *game);
void			move_player_left(t_game *game);
void			move_player_right(t_game *game);

// SPRITE FUNCTIONS
void			sprite_creator(t_game *game, char *path, int i, int j);
void			sprite_exit(t_game *game, int i, int j);
void			sprite_characters(t_map *map, t_game *game);

void			sprite_covers(t_game *game, t_map *map);
void			sprite_map(t_game *game);

void			frames_first_animation(t_game *game);
void			frames_move_right(t_game *game, int x, int y);
void        frames_stay(t_game *game, int x, int y);
void	sprite_player(t_game *game);


// MENSSAGE FUNCTIONS
void			show_error(char *str);
void			show_win(char *str);
void			show_moves(t_game *game);

#endif