/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_charger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:27:36 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/22 21:58:22 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	int	i;

	i = -1;
	while (++i < 1)
	{
		if (game->frames <= 4)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk16, x,
				y);
		else if (game->frames <= 10)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk17, x,
				y);
		else if (game->frames <= 14)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk18, x,
				y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x,
				y);
	}
}

void	frames_move_down(t_game *game, int x, int y)
{
	int	i;

	i = -1;
	while (++i < 1)
	{
		if (game->frames <= 4)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk16, x,
				y - PIXELS);
		else if (game->frames <= 8)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk17, x,
				y - PIXELS);
		else if (game->frames <= 10)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk18, x,
				y - PIXELS);
		else if (game->frames <= 12)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk18, x,
				y);
		else if (game->frames <= 14)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk17, x,
				y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x,
				y);
	}
}

void	frames_move_left(t_game *game, int x, int y)
{
	int	i;

	i = -1;
	while (++i < 1)
	{
		if (game->frames <= 12)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk10, x,
				y);
		else if (game->frames <= 20)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk13, x,
				y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x,
				y);
	}
}

void	frames_move_right(t_game *game, int x, int y)
{
	int	i;

	i = -1;
	while (++i < 1)
	{
		if (game->frames <= 6)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk11, x
				- PIXELS, y);
		else if (game->frames <= 9)
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gk15, x
				- 32, y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->inits->gkb, x,
				y);
	}
}
