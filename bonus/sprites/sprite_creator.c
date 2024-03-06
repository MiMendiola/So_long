/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:53:29 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/06 17:38:24 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	*load_image(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		height;

	width = PIXELS;
	height = PIXELS;
	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img)
		show_error(ERROR_LOADING_IMG);
	return (img);
}

static void	*load_cover(t_game *game, char *path)
{
	void	*cover;
	int	width;
	int	height;
	int	x;
	int	y;

	x = ft_strlen(game->map_check[0]);
	y = 0;
	while (game->map_check[y])
		y++;
	width = PIXELS * x;
	height = PIXELS * y;
	cover = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!cover)
		show_error(ERROR_LOADING_IMG);
	return (cover);
}

static void	create_sprites_gokubase(t_game *game)
{
	game->inits->gkb = load_image(game, GOKUBASE);
	game->inits->gk1 = load_image(game, GOKUBASE1);
	game->inits->gk2 = load_image(game, GOKUBASE2);
	game->inits->gk3 = load_image(game, GOKUBASE3);
	game->inits->gk4 = load_image(game, GOKUBASE4);
	game->inits->gk5 = load_image(game, GOKUBASE5);
	game->inits->gk6 = load_image(game, GOKUBASE6);
	game->inits->gk7 = load_image(game, GOKUBASE7);
	game->inits->gk8 = load_image(game, GOKUBASE8);
	game->inits->gk9 = load_image(game, GOKUBASE9);
	game->inits->gk10 = load_image(game, GOKUBASE10);
	game->inits->gk11 = load_image(game, GOKUBASE11);
	game->inits->gk12 = load_image(game, GOKUBASE12);
	game->inits->gk13 = load_image(game, GOKUBASE13);
	game->inits->gk15 = load_image(game, GOKUBASE15);
	game->inits->gk16 = load_image(game, GOKUBASE16);
	game->inits->gk17 = load_image(game, GOKUBASE17);
	game->inits->gk18 = load_image(game, GOKUBASE18);
}

static void	create_sprites_objs(t_game *game)
{
	game->inits->floo = load_image(game, FLOOR);
	game->inits->wall = load_image(game, WALLS);
	game->inits->eneb = load_image(game, ENEMY);
	game->inits->bal1 = load_image(game, BALL1);
	game->inits->bal2 = load_image(game, BALL2);
	game->inits->bal3 = load_image(game, BALL3);
	game->inits->bal4 = load_image(game, BALL4);
	game->inits->bal5 = load_image(game, BALL5);
	game->inits->bal6 = load_image(game, BALL6);
	game->inits->bal7 = load_image(game, BALL7);
	game->inits->ex1 = load_image(game, EXIT1);
	game->inits->ex2 = load_image(game, EXIT2);
	game->inits->ex3 = load_image(game, EXIT3);
	game->inits->ex4 = load_image(game, EXIT4);
	game->inits->ex5 = load_image(game, EXIT5);
	game->inits->ex6 = load_image(game, EXIT6);
	game->inits->ex7 = load_image(game, EXIT7);
	game->inits->cv1 = load_cover(game, COVERGOKU1);
}

void	creator_sprites(t_game *game)
{
	game->inits = ft_calloc(1, sizeof(t_init_sprites));
	create_sprites_objs(game);
	create_sprites_gokubase(game);
}
