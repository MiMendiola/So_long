/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:25:21 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/08 18:26:54 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sprite_characters(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_check[++i])
	{
		j = -1;
		while (game->map_check[i][++j])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->inits->floo, j
				* PIXELS, i * PIXELS);
			if (game->map_check[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->inits->wall,
					j * PIXELS, i * PIXELS);
			else if (game->map_check[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->inits->bal1,
					j * PIXELS, i * PIXELS);
			else if (game->map_check[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb,
					j * PIXELS, i * PIXELS);
			else if (game->map_check[i][j] == 'B')
				mlx_put_image_to_window(game->mlx, game->win, game->inits->eneb,
					j * PIXELS, i * PIXELS);
		}
	}
}

void	sprite_exit(t_game *game, int i, int j)
{
	if (game->balls == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->ex1, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->ex2, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->ex3, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->ex4, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 5)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->ex5, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->ex6, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 7)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->ex7, j
			* PIXELS, i * PIXELS);
}

void	sprite_map(t_game *game)
{
	sprite_characters(game);
	if (game->items == 0)
	{
		game->map_check[game->exity][game->exitx] = 'E';
		sprite_exit(game, game->exity, game->exitx);
	}
}
