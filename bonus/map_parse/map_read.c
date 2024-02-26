/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:35:28 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/26 14:07:28 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	*map_copy(t_map *map, int fd)
{
	int		i;
	int		line_lenght;
	char	*cmap;
	char	*cpy_aux;
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
			show_error(ERROR_NOT_RECTANGULAR);
		cpy_aux = ft_strdup(cmap);
		free(cmap);
		cmap = ft_strjoin(cpy_aux, line);
		free(cpy_aux);
		free(line);
	}
	if (cmap[0] == '\n' || cmap[ft_strlen(cmap) - 1] == '\n')
		show_error(ERROR_FIRST_LAST_LINE);
	return (cmap);
}

static void	map_collect(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
				show_error(ERROR_NOT_ALL_COLLECTS);
			if (map->map[i][j] == 'E')
				show_error(ERROR_NOT_EXIT);
		}
	}
}

static void	map_floodfill_path(t_map *map, int x, int y)
{
	if (map->map[x][y] == '1' || map->map[x][y] == ' ' || map->map[x][y] == 'B')
		return ;
	map->map[x][y] = ' ';
	map_floodfill_path(map, x, y + 1);
	map_floodfill_path(map, x + 1, y);
	map_floodfill_path(map, x, y - 1);
	map_floodfill_path(map, x - 1, y);
}

static void	check_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->steps = 0;
	game->flags.evolution = 0;
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
			if (game->map_check[i][j] == 'E')
			{
				game->exitx = j;
				game->exity = i;
			}
		}
	}
}

void	map_read(t_map *map, t_game *game, char *file)
{
	int		fd;
	char	*cmap;

	map_ext(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		show_error(ERROR_FILE);
	map_dimensions(map, file);
	cmap = map_copy(map, fd);
	map->map = ft_split(cmap, '\n');
	game->map_check = ft_split(cmap, '\n');
	free(cmap);
	map_borders(map);
	map_characters(map, game);
	check_player(game);
	map_floodfill_path(map, map->player.posy, map->player.posx);
	map_collect(map);
	close(fd);
}
