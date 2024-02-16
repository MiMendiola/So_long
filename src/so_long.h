/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:48:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/16 15:22:27 by mmendiol         ###   ########.fr       */
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
	int			steps;
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

// MENSSAGE FUNCTIONS
void			show_error(char *str);
void			show_win(char *str);

#endif