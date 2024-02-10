/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:25:21 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/10 16:16:25 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static  void	sprite_creator(t_game *game, char *path, int i, int j)
{
	t_sprites	*img;
	int			posx;
	int			posy;

	img = malloc(sizeof(t_sprites));
	img->path = path;
	img->img_w = 52;
	img->img_h = 52;
	posx = j * 52;
	posy = i * 52;
	img = mlx_xpm_file_to_image(game->mlx, img->path, &img->img_w, &img->img_h);
	if (!img)
	{
		show_error("Error loading image\n");
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->win, img, posx, posy);
}

static void	sprite_floor(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_copy[i])
	{
		j = 0;
		while (map->map_copy[i][j] && map->map_copy[i][j] != '\n')
		{
			sprite_creator(game, "./textures/suelo.xpm", i, j);
			j++;
		}
		i++;
	}
}

static void	sprite_balls(t_map *map, t_game *game, int i, int j)
{
	if (map->balls == 1)
		sprite_creator(game, "./textures/balls/ball1.xpm", i, j);
	else if (map->balls == 2)
		sprite_creator(game, "./textures/balls/ball2.xpm", i, j);
	else if (map->balls == 3)
		sprite_creator(game, "./textures/balls/ball3.xpm", i, j);
	else if (map->balls == 4)
		sprite_creator(game, "./textures/balls/ball4.xpm", i, j);
	else if (map->balls == 5)
		sprite_creator(game, "./textures/balls/ball5.xpm", i, j);
	else if (map->balls == 6)
		sprite_creator(game, "./textures/balls/ball6.xpm", i, j);
	else if (map->balls == 7)
		sprite_creator(game, "./textures/balls/ball7.xpm", i, j);
	map->balls--;
}

static void	sprite_exit(t_map *map, t_game *game, int i, int j)
{
	if (map->items == 1)
		sprite_creator(game, "./textures/balls/ball1.xpm", i, j);
	else if (map->items == 2)
		sprite_creator(game, "./textures/exit/exit2.xpm", i, j);
	else if (map->items == 3)
		sprite_creator(game, "./textures/exit/exit3.xpm", i, j);
	else if (map->items == 4)
		sprite_creator(game, "./textures/exit/exit4.xpm", i, j);
	else if (map->items == 5)
		sprite_creator(game, "./textures/exit/exit5.xpm", i, j);
	else if (map->items == 6)
		sprite_creator(game, "./textures/exit/exit6.xpm", i, j);
	else if (map->items == 7)
		sprite_creator(game, "./textures/exit/exit7.xpm", i, j);
}

void	sprite_characters(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	sprite_floor(map, game);
	while (map->map_copy[i])
	{
		j = 0;
		while (map->map_copy[i][j] && map->map_copy[i][j] != '\n')
		{
			if (map->map_copy[i][j] == 'P')
				sprite_creator(game, "./textures/gogeta_wait.xpm", i, j);
			else if (map->map_copy[i][j] == 'E')
				sprite_exit(map, game, i, j);
			else if (map->map_copy[i][j] == 'C')
				sprite_balls(map, game, i, j);
			else if (map->map_copy[i][j] == '1')
				sprite_creator(game, "./textures/wall.xpm", i, j);
			else if (map->map_copy[i][j] == '0')
				sprite_creator(game, "./textures/suelo.xpm", i, j);
			j++;
		}
		i++;
	}
}
