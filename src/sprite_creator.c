/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:25:21 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/16 15:21:32 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	sprite_floor(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_check[i])
	{
		j = 0;
		while (game->map_check[i][j] && game->map_check[i][j] != '\n')
		{
			sprite_creator(game, FLOOR, i, j);
			j++;
		}
		i++;
	}
}

static void	sprite_balls(t_map *map, t_game *game, int i, int j)
{
	if (map->items == 1)
		sprite_creator(game, BALL1, i, j);
	else if (map->items == 2)
		sprite_creator(game, BALL2, i, j);
	else if (map->items == 3)
		sprite_creator(game, BALL3, i, j);
	else if (map->items == 4)
		sprite_creator(game, BALL4, i, j);
	else if (map->items == 5)
		sprite_creator(game, BALL5, i, j);
	else if (map->items == 6)
		sprite_creator(game, BALL6, i, j);
	else if (map->items == 7)
		sprite_creator(game, BALL7, i, j);
	map->items--;
}

void	sprite_creator(t_game *game, char *path, int i, int j)
{
	int			posx;
	int			posy;

	game->ptr->path = path;
	game->ptr->img_w = PIXELS;
	game->ptr->img_h = PIXELS;
	posx = j * PIXELS;
	posy = i * PIXELS;
	game->ptr->img = mlx_xpm_file_to_image(game->mlx, game->ptr->path, &game->ptr->img_w, &game->ptr->img_h);
	if (!game->ptr->img)
		show_error(ERROR_LOADING_IMG);
	mlx_put_image_to_window(game->mlx, game->win, game->ptr->img, posx, posy);
}

void	sprite_exit(t_game *game, int i, int j)
{
	if (game->balls == 1)
		sprite_creator(game, BALL1, i, j);
	else if (game->balls == 2)
		sprite_creator(game, EXIT2, i, j);
	else if (game->balls == 3)
		sprite_creator(game, EXIT3, i, j);
	else if (game->balls == 4)
		sprite_creator(game, EXIT4, i, j);
	else if (game->balls == 5)
		sprite_creator(game, EXIT5, i, j);
	else if (game->balls == 6)
		sprite_creator(game, EXIT6, i, j);
	else if (game->balls == 7)
		sprite_creator(game, EXIT7, i, j);
}

void	sprite_characters(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	sprite_floor(game);
	while (game->map_check[i])
	{
		j = 0;
		while (game->map_check[i][j] && game->map_check[i][j] != '\n')
		{
			if (game->map_check[i][j] == 'P')
				sprite_creator(game, GOKUBASE, i, j);
			else if (game->map_check[i][j] == 'C')
				sprite_balls(map, game, i, j);
			else if (game->map_check[i][j] == '1')
				sprite_creator(game, WALLS, i, j);
			j++;
		}
		i++;
	}
}
