/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:33:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/26 14:07:28 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	walls_detector(t_game *game, int flag, int row, int col)
{
	if (game->map_check[row][col] != '1')
	{
		game->flags.dir = flag;
		if (game->flags.dir == UP)
			move_player_up(game);
		if (game->flags.dir == DOWN)
			move_player_down(game);
		if (game->flags.dir == LEFT)
			move_player_left(game);
		if (game->flags.dir == RIGHT)
			move_player_right(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		walls_detector(game, UP, game->player.posy - 1, game->player.posx);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		walls_detector(game, LEFT, game->player.posy, game->player.posx - 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		walls_detector(game, DOWN, game->player.posy + 1, game->player.posx);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		walls_detector(game, RIGHT, game->player.posy, game->player.posx + 1);
	return (0);
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
	show_moves(game);
	if (game->frames >= 60)
		game->flags.dir = STAY;
	frames_counter(game);
	return (0);
}

void	game_init(t_game *game, t_map *map)
{
	game->image = malloc(sizeof(t_sprites));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (map->map_w * PIXELS), (map->map_h
				* PIXELS), "Goku Evolved");
	generator_sprites(game);
	mlx_hook(game->win, ON_DESTROY, 0, close_cross, game);
	mlx_key_hook(game->win, key_press, game);
	mlx_loop_hook(game->mlx, frame_executor, game);
	mlx_loop(game->mlx);
}
