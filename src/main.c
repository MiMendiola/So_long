/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/19 19:50:36 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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
	if (game->frames >= 30)
	{
		game->frames = 0;
		game->flags.first_animation = 1;
	}
	game->frames++;
	return (0);
}

int		frame_executor(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	sprite_map(game);
	show_moves(game);
	frames_counter(game);
	return (0);
}

static	void	game_init(t_game *game, t_map *map)
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

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int ac, char *av[])
{
	t_map	*map;
	t_game	*game;

	// atexit(ft_leaks);
	map = ft_calloc(1, sizeof(t_map));
	game = ft_calloc(1, sizeof(t_game));
	if (ac != 2)
	{
		show_error("Bad arguments\n");
	}
	else
	{
		map_read(map, game, av[1]);
		game_init(game, map);
	}
	free(map);
	free(game);
	return (0);
}
