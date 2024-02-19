/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:48:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/19 20:12:32 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_ext/libft.h"
# include "../mlx/mlx.h"
# include "./defines.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ================== STRUCTS ================== */
typedef struct s_flags
{
	int				first_animation;
	int				evolution;
}					t_flags;

typedef struct s_player
{
	int				posx;
	int				posy;
}					t_player;

typedef struct s_sprites
{
	void			*img;
	char			*path;
	int				img_w;
	int				img_h;
}					t_sprites;

typedef struct s_init_sprites
{
	void			*floo;
	void			*wall;
	void			*bal1;
	void			*bal2;
	void			*bal3;
	void			*bal4;
	void			*bal5;
	void			*bal6;
	void			*bal7;
	void			*ex1;
	void			*ex2;
	void			*ex3;
	void			*ex4;
	void			*ex5;
	void			*ex6;
	void			*ex7;
	void			*gkb;
	void			*gk1;
	void			*gk2;
	void			*gk3;
	void			*gk4;
	void			*gk5;
	void			*gk6;
	void			*gk7;
	void			*gk8;
	void			*gk9;
	void			*gk10;
	void			*gk11;
	void			*gk12;
	void			*gk13;
	void			*gk14;
	void			*gk15;
}					t_init_sprites;

typedef struct s_map
{
	char			**map;
	int				map_w;
	int				map_h;
	int				main_char;
	int				exit;
	int				items;
	int				balls;
	t_player		player;
}					t_map;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map_check;
	int				items;
	int				balls;
	int				steps;
	int				exitX;
	int				exitY;
	int				frames;
	t_init_sprites	*initS;
	t_sprites		*image;
	t_player		player;
	t_flags			flags;
}					t_game;

/* =============== MAP FUNCTIONS =============== */
void				map_read(t_map *map, t_game *game, char *file);
char				*map_copy(t_map *map, int fd);
void				check_player(t_game *game);

/* ============ MOVEMENTS FUNCTIONS ============ */
void				movement_goku_base(t_game *game, int posx, int posy);
void				move_player_up(t_game *game);
void				move_player_down(t_game *game);
void				move_player_left(t_game *game);
void				move_player_right(t_game *game);

/* ============= SPRITE FUNCTIONS ============== */
void				sprite_creator(t_game *game, char *path, int i, int j);

void				frames_first_animation(t_game *game);
void				frames_stay(t_game *game, int x, int y);
void				sprite_player(t_game *game, int row, int col);

/* ============= SPRITE GENERATOR ============== */
void				*load_image(t_game *game, char *path);
void				generator_sprites(t_game *game);

/* ============== SPRITE CREATOR =============== */
void				sprite_map(t_game *game);
void				sprite_characters(t_game *game);
void				sprite_exit(t_game *game, int i, int j);
void				sprite_balls(t_game *game, int i, int j);

/* ============ MENSSAGE FUNCTIONS ============= */
void				show_error(char *str);
void				show_win(char *str);
void				show_moves(t_game *game);

#endif