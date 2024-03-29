/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/26 15:28:02 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	ft_leaks(void)
// {
// 	system("leaks -q so_long");
// }

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
