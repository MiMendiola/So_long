/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:25:21 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/19 20:13:16 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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
			mlx_put_image_to_window(game->mlx, game->win, game->initS->floo, j
				* PIXELS, i * PIXELS);
			if (game->map_check[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->initS->wall,
					j * PIXELS, i * PIXELS);
			else if (game->map_check[i][j] == 'C')
				sprite_balls(game, i, j);
			else if (game->map_check[i][j] == 'P')
				sprite_player(game, j * PIXELS, i * PIXELS);
		}
	}
}

// static void	sprite_balls(t_map *map, t_game *game, int i, int j)
// {
// 	if (map->items == 1)
// 		sprite_creator(game, BALL1, i, j);
// 	else if (map->items == 2)
// 		sprite_creator(game, BALL2, i, j);
// 	else if (map->items == 3)
// 		sprite_creator(game, BALL3, i, j);
// 	else if (map->items == 4)
// 		sprite_creator(game, BALL4, i, j);
// 	else if (map->items == 5)
// 		sprite_creator(game, BALL5, i, j);
// 	else if (map->items == 6)
// 		sprite_creator(game, BALL6, i, j);
// 	else if (map->items == 7)
// 		sprite_creator(game, BALL7, i, j);
// 	map->items--;
// }

void	sprite_creator(t_game *game, char *path, int i, int j)
{
	int	posx;
	int	posy;

	game->image->path = path;
	game->image->img_w = PIXELS;
	game->image->img_h = PIXELS;
	posx = j * PIXELS;
	posy = i * PIXELS;
	game->image->img = mlx_xpm_file_to_image(game->mlx, game->image->path,
		&game->image->img_w, &game->image->img_h);
	if (!game->image->img)
		show_error(ERROR_LOADING_IMG);
	mlx_put_image_to_window(game->mlx, game->win, game->image->img, posx, posy);
}

void	sprite_balls(t_game *game, int i, int j)
{
	if (game->balls == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->bal1, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->bal2, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->bal3, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->bal4, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 5)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->bal5, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->bal6, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 7)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->bal7, j
			* PIXELS, i * PIXELS);
}

void	sprite_exit(t_game *game, int i, int j)
{
	if (game->balls == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->ex1, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->ex2, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->ex3, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->ex4, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 5)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->ex5, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->ex6, j
			* PIXELS, i * PIXELS);
	else if (game->balls == 7)
		mlx_put_image_to_window(game->mlx, game->win, game->initS->ex7, j
			* PIXELS, i * PIXELS);
}

void	sprite_map(t_game *game)
{
	sprite_characters(game);
	if (game->items == 0)
	{
		game->map_check[game->exitY][game->exitX] = 'E';
		sprite_exit(game, game->exitY, game->exitX);
	}
}

void	sprite_player(t_game *game, int row, int col)
{
	if (game->flags.first_animation == 0)
		frames_first_animation(game);
	else
		frames_stay(game, row, col);
}
