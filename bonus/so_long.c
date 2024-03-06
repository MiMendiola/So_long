/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/03/06 17:30:17 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	ft_leaks(void)
// {
// 	system("leaks -q so_long");
// }
// atexit(ft_leaks);

int	close_cross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_map	*map;
	t_game	*game;

	map = ft_calloc(1, sizeof(t_map));
	game = ft_calloc(1, sizeof(t_game));
	if (ac != 2)
		show_error("Bad arguments\n");
	else
	{
		map_read(map, game, av[1]);
		game_init(game, map);
	}
	return (0);
}
