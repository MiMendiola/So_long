/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_charger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:27:36 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/26 14:07:28 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	frames_stay(t_game *game, int x, int y)
{
	if (game->frames <= 8)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x, y);
	else if (game->frames <= 14)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk4, x, y);
	else if (game->frames <= 20)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk5, x, y);
	else if (game->frames <= 26)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk4, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x, y);
}

void	frames_move_up(t_game *game, int x, int y)
{
	x *= PIXELS;
	y *= PIXELS;
	if (game->frames <= 8)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x, y
			- 1);
	else if (game->frames <= 14)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk11, x, y
			- 1);
	if (game->frames <= 20)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk15, x, y
			- 1);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x, y
			- 1);
}

void	frames_move_down(t_game *game, int x, int y)
{
	x *= PIXELS;
	y *= PIXELS;
	if (game->frames <= 8)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x, y
			+ 1);
	else if (game->frames <= 14)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk11, x, y
			+ 1);
	if (game->frames <= 20)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk15, x, y
			+ 1);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x, y
			+ 1);
}

void	frames_move_left(t_game *game, int x, int y)
{
	x *= PIXELS;
	y *= PIXELS;
	if (game->frames <= 8)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x - 1,
			y);
	else if (game->frames <= 14)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk11, x - 1,
			y);
	if (game->frames <= 20)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk15, x - 1,
			y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x - 1,
			y);
}

void	frames_move_right(t_game *game, int x, int y)
{
	x *= PIXELS;
	y *= PIXELS;
	if (game->frames <= 8)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x + 1,
			y);
	else if (game->frames <= 14)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk11, x + 1,
			y);
	if (game->frames <= 20)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gk15, x + 1,
			y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x + 1,
			y);
}
