/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:25:21 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/04 17:33:49 by mmendiol         ###   ########.fr       */
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
				sprite_balls(game, i, j);
			else if (game->map_check[i][j] == 'P')
				sprite_player(game, j * PIXELS, i * PIXELS);
			else if (game->map_check[i][j] == 'F')
				mlx_put_image_to_window(game->mlx, game->win, game->inits->eneb,
					j * PIXELS, i * PIXELS);
		}
	}
}

// void	sprite_creator(t_game *game, char *path, int i, int j)
// {
// 	int	posx;
// 	int	posy;

// 	game->image->path = path;
// 	game->image->img_w = PIXELS;
// 	game->image->img_h = PIXELS;
// 	posx = j * PIXELS;
// 	posy = i * PIXELS;
// 	game->image->img = mlx_xpm_file_to_image(game->mlx, game->image->path,
// 			&game->image->img_w, &game->image->img_h);
// 	if (!game->image->img)
// 		show_error(ERROR_LOADING_IMG);
// 	mlx_put_image_to_window(game->mlx, game->win, game->image->img, posx, posy);
// }

void	sprite_balls(t_game *game, int i, int j)
{
	if (game->balls == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->bal1, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->bal2, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->bal3, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->bal4, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 5)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->bal5, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->bal6, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 7)
		mlx_put_image_to_window(game->mlx, game->win, game->inits->bal7, j
			* PIXELS, i * PIXELS);
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
	if (game->flags.fcover < ft_strlen(game->map_check[0]) / 3)
		sprite_covers(game, game->flags.fcover);
	else
	{
		sprite_characters(game);
		if (game->items == 0)
		{
			game->map_check[game->exity][game->exitx] = 'E';
			sprite_exit(game, game->exity, game->exitx);
		}
	}
}

void	sprite_player(t_game *game, int row, int col)
{
	if (game->flags.dir == UP)
		frames_move_up(game, row, col);
	if (game->flags.dir == DOWN)
		frames_move_down(game, row, col);
	if (game->flags.dir == LEFT)
		frames_move_left(game, row, col);
	if (game->flags.dir == RIGHT)
		frames_move_right(game, row, col);
	if (game->flags.dir == STAY)
		frames_stay(game, row, col);
}
