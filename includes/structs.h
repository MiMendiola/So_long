/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:03:04 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/22 20:24:37 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_flags
{
	int				fcover;
	int				dir;
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
	void			*eneb;
	void			*cv1;
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
	void			*gk15;
	void			*gk16;
	void			*gk17;
	void			*gk18;
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
	int				enemy;
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
	int				exitx;
	int				exity;
	int				frames;
	t_init_sprites	*inits;
	t_sprites		*image;
	t_player		player;
	t_flags			flags;
}					t_game;