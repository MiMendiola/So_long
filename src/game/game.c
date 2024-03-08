/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:33:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/08 18:23:45 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player_up(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player_left(game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player_down(game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player_right(game);
	return (0);
}

int	close_cross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

int	frames_counter(t_game *game)
{
	if (game->frames >= 60)
	{
		game->frames = 0;
		game->flags.fcover++;
	}
	game->frames++;
	return (0);
}

int	frame_executor(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	sprite_map(game);
	frames_counter(game);
	return (0);
}

void	game_init(t_game *game, t_map *map)
{
	game->image = malloc(sizeof(t_sprites));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (map->map_w * PIXELS), (map->map_h
				* PIXELS), "Goku Evolved");
	creator_sprites(game);
	mlx_hook(game->win, ON_DESTROY, 0, close_cross, game);
	mlx_key_hook(game->win, key_press, game);
	mlx_loop_hook(game->mlx, frame_executor, game);
	mlx_loop(game->mlx);
}
