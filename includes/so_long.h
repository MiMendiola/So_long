/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:48:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/22 22:06:42 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_ext/libft.h"
# include "../mlx/mlx.h"
# include "./defines.h"
# include "./structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ============= SO_LONG FUNCTIONS ============= */
void	game_init(t_game *game, t_map *map);

/* =============== MAIN FUNTIONS =============== */
int		close_cross(t_game *game);

/* =============== MAP FUNCTIONS =============== */
void	map_ext(const char *str, const char *to_find);
void	map_dimensions(t_map *map, char *file);
void	map_borders(t_map *map);
void	map_characters(t_map *map, t_game *game);
void	map_read(t_map *map, t_game *game, char *file);

/* ============ MOVEMENTS FUNCTIONS ============ */
void	movement_goku_base(t_game *game, int posx, int posy);
void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);

/* ============= FRAMES FUNCTIONS ============== */
void	frames_stay(t_game *game, int x, int y);
void	frames_move_up(t_game *game, int x, int y);
void	frames_move_down(t_game *game, int x, int y);
void	frames_move_left(t_game *game, int x, int y);
void	frames_move_right(t_game *game, int x, int y);

/* =============== SPRITE COVER ================ */
void	sprite_covers(t_game *game, int posx);

/* ============== SPRITE CREATOR =============== */
void	sprite_characters(t_game *game);
void	sprite_balls(t_game *game, int i, int j);
void	sprite_exit(t_game *game, int i, int j);
void	sprite_map(t_game *game);
void	sprite_player(t_game *game, int row, int col);

/* ============= SPRITE GENERATOR ============== */
void	generator_sprites(t_game *game);

/* ============ MESSAGE FUNCTIONS ============= */
void	show_moves(t_game *game);
void	show_error(char *str);
void	show_win(void);
void	show_lose(void);

#endif