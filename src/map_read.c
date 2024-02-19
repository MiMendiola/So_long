/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:45:16 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/19 16:35:05 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static	void	map_ext(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (str[i + j + 1] == '\0' && to_find[j + 1] == '\0')
				return ;
			j++;
		}
		i++;
	}
	show_error(ERROR_EXTENSION_MAP);
}

static	void	map_dimensions(t_map *map, char *file)
{
	int	fd;
	int	height;
	int	width;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		show_error(ERROR_FILE);
	line = get_next_line(fd);
	width = ft_strlen(line) - 1;
	free(line);
	height = 0;
	while (line)
	{
		line = get_next_line(fd);
		height++;
		free(line);
	}
	close(fd);
	map->map_h = height;
	map->map_w = width;
	map->main_char = 0;
	map->exit = 0;
	map->items = 0;
}

static	void	map_borders(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j] && map->map[i][j] != '\n')
		{
			if ((map->map[0][j] != '1') || (map->map[map->map_h
					- 1][j] != '1') || (map->map[i][0] != '1')
				|| (map->map[i][map->map_w - 1] != '1'))
				show_error(ERROR_NOT_WALLS);
			j++;
		}
		i++;
	}
}

static	void	map_characters(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				map->main_char += 1;
			else if (map->map[i][j] == 'E')
				map->exit += 1;
			else if (map->map[i][j] == 'C')
				map->items += 1;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0')
				show_error(ERROR_MAP_ELEMENTS);
		}
	}
	map->balls = map->items;
	game->items = map->items;
	game->balls = map->items;
	if (map->main_char != 1 || map->exit != 1 || map->balls == 0 || map->balls > 7)
		show_error(ERROR_CHARACTERS_NOT_VALID);
}

void	map_read(t_map *map, t_game *game, char *file)
{
	int		fd;
	char 	*cmap;

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
	close(fd);
}
