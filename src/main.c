/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/12 21:14:10 by mmendiol         ###   ########.fr       */
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


int	closete(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

void	game_init(t_game *game, t_map *map, char *file)
{
	map_read(map, file);
	game->ptr = malloc(sizeof(t_sprites)); 

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (map->map_w * 52), (map->map_h * 52),
		"Goku Evolved");
	
	sprite_characters(map, game);
	//mlx_hook(game->win, ON_DESTROY, 0, closete, &game->win);
	mlx_key_hook(game->win, closete, game);
	mlx_loop(game->mlx);
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
