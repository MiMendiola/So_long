/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:35:28 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/13 20:32:30 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

char	*map_copy(t_map *map, int fd)
{
	int		i;
	int		line_lenght;
	char 	*cmap;
	char 	*cpy_aux;
	char	*line;

	i = -1;
	line_lenght = 0;
	cmap = ft_strdup("");
	while (++i < map->map_h)
	{
		line = get_next_line(fd);
		if ((line[ft_strlen(line) - 1]) == '\n')
			line_lenght = ft_strlen(line) - 1;
		if (line && map->map_w != line_lenght)
			show_error("Map is not rectangular\n");
		cpy_aux = ft_strdup(cmap);
		free(cmap);
		cmap = ft_strjoin(cpy_aux, line);
		free(cpy_aux);
		free(line);
	}
	if (cmap[0] == '\n' || cmap[ft_strlen(cmap) - 1] == '\n')
		show_error("Check the first or last line of your map\n");
	return (cmap);
}

void	check_player(t_game *game)
{
	int i;
	int j;

	i = -1;
	game->player.steps = 0;
	while (game->map_check[++i])
	{
		j = -1;
		while (game->map_check[i][++j])
		{
			if (game->map_check[i][j] == 'P')
			{
				game->player.posx = j;
				game->player.posy = i;
			}
		}
	}
}
