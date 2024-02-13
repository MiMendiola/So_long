/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/13 20:41:39 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

// #include "./message.c"
// #include "../libft_ext/libft.h"
// #include "../libft_ext/ft_putstr_fd.c"
// #include "../libft_ext/ft_strjoin.c"
// #include "../libft_ext/ft_memcpy.c"
// #include "../libft_ext/ft_calloc.c"
// #include "../libft_ext/ft_strlen.c"
// #include "../libft_ext/ft_strtrim.c"
// #include "../libft_ext/ft_strdup.c"
// #include "../libft_ext/ft_strchr.c"
// #include "../libft_ext/ft_substr.c"
// #include "../libft_ext/ft_bzero.c"
// #include "../libft_ext/ft_memset.c"
// #include "../libft_ext/get_next_line.c"
// #include "../libft_ext/get_next_line_utils.c"


int	key_press(int keycode, t_game *game, t_map *map)
{
	map = NULL;
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

void	game_init(t_game *game, t_map *map, char *file)
{
	map_read(map, game, file);
	check_player(game);
	game->ptr = malloc(sizeof(t_sprites)); 

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (map->map_w * 52), (map->map_h * 52),
		"Goku Evolved");
	
	sprite_characters(map, game);
	printf("%d\n", game->player.posx);
	printf("%d\n", game->player.posy);
	mlx_hook(game->win, ON_DESTROY, 0, close_cross, game);
	mlx_key_hook(game->win, key_press, game);
	mlx_loop(game->mlx);
}

void	move_player_up(t_game *game)
{
	printf("W o Arrow up, Posicion: ");
	game->player.posy--;
	printf("%d\n", game->player.posy);
}

void	move_player_down(t_game *game)
{
	printf("S o Arrow down, Posicion: ");
	game->player.posy++;
	printf("%d\n", game->player.posy);
}

void	move_player_left(t_game *game)
{
	printf("A o Arrow left, Posicion: ");
	game->player.posx--;
	printf("%d\n", game->player.posx);
}

void	move_player_right(t_game *game)
{
	printf("D o Arrow right, Posicion: ");
	game->player.posx++;
	printf("%d\n", game->player.posx);
}

void ft_leaks()
{
	system("leaks -q so_long");
}

int	main(int ac, char *av[])
{
	t_map	*map;
	t_game	*game;

	//atexit(ft_leaks);
	map = ft_calloc(1, sizeof(t_map));
	game = ft_calloc(1, sizeof(t_game));
	if (ac != 2)
	{
		show_error("Bad arguments\n");
	}
	else
	{
		game_init(game, map, av[1]);
		 
	}
	free(map->map);
	free(map);
	free(game);
	return (0);
}
