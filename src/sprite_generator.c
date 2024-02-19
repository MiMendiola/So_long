/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:53:29 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/19 20:04:06 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	*load_image(t_game *game, char *path)
{
	int	width;
	int	height;

	width = PIXELS;
	height = PIXELS;
	return (mlx_xpm_file_to_image(game->mlx, path, &width, &height));
}

static  void	generate_sprites_gokuBase(t_game *game)
{
	game->initS->gkb = load_image(game, GOKUBASE);
	game->initS->gk1 = load_image(game, GOKUBASE1);
	game->initS->gk2 = load_image(game, GOKUBASE2);
	game->initS->gk3 = load_image(game, GOKUBASE3);
	game->initS->gk4 = load_image(game, GOKUBASE4);
	game->initS->gk5 = load_image(game, GOKUBASE5);
	game->initS->gk6 = load_image(game, GOKUBASE6);
	game->initS->gk7 = load_image(game, GOKUBASE7);
	game->initS->gk8 = load_image(game, GOKUBASE8);
	game->initS->gk9 = load_image(game, GOKUBASE9);
	game->initS->gk10 = load_image(game, GOKUBASE10);
	game->initS->gk11 = load_image(game, GOKUBASE11);
	game->initS->gk12 = load_image(game, GOKUBASE12);
	game->initS->gk13 = load_image(game, GOKUBASE13);
	game->initS->gk14 = load_image(game, GOKUBASE14);
	game->initS->gk15 = load_image(game, GOKUBASE15);
}

static  void	generate_sprites_objs(t_game *game)
{

    game->initS->floo = load_image(game, FLOOR);
	game->initS->wall = load_image(game, WALLS);
	game->initS->bal1 = load_image(game, BALL1);
	game->initS->bal2 = load_image(game, BALL2);
	game->initS->bal3 = load_image(game, BALL3);
	game->initS->bal4 = load_image(game, BALL4);
	game->initS->bal5 = load_image(game, BALL5);
	game->initS->bal6 = load_image(game, BALL6);
	game->initS->bal7 = load_image(game, BALL7);
	game->initS->ex1 = load_image(game, EXIT1);
	game->initS->ex2 = load_image(game, EXIT2);
	game->initS->ex3 = load_image(game, EXIT3);
	game->initS->ex4 = load_image(game, EXIT4);
	game->initS->ex5 = load_image(game, EXIT5);
	game->initS->ex6 = load_image(game, EXIT6);
	game->initS->ex7 = load_image(game, EXIT7);
}

void    generator_sprites(t_game *game)
{
    game->initS = ft_calloc(1, sizeof(t_init_sprites));

    generate_sprites_objs(game);
    generate_sprites_gokuBase(game);
}
