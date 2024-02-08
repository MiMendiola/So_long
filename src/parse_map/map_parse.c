/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:45:16 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/08 19:52:49 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_ext(const char *str, const char *to_find)
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
	show_error("Please, check the map extension\n");
}

static void	map_dimensions(t_map *map, char *file)
{
	int	fd;
	int	height;
	int	width;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		show_error("File error\n");
	width = ft_strlen(ft_strtrim(get_next_line(fd), "\n"));
	height = 1;
	while (get_next_line(fd))
		height++;
	close(fd);
	map->map_h = height;
	map->map_w = width;
	map->player = 0;
	map->exit = 0;
	map->items = 0;
}

static void	map_borders(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_copy[i])
	{
		j = 0;
		while (map->map_copy[i][j] && map->map_copy[i][j] != '\n')
		{
			if ((map->map_copy[0][j] != '1') || (map->map_copy[map->map_h
					- 1][j] != '1') || (map->map_copy[i][0] != '1')
				|| (map->map_copy[i][map->map_w - 1] != '1'))
				show_error("Map not surrounded by walls\n");
			j++;
		}
		i++;
	}
}

static void	map_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_copy[i])
	{
		j = 0;
		while (map->map_copy[i][j] && map->map_copy[i][j] != '\n')
		{
			if (map->map_copy[i][j] == 'P')
				map->player += 1;
			else if (map->map_copy[i][j] == 'E')
				map->exit += 1;
			else if (map->map_copy[i][j] == 'C')
				map->items += 1;
			else if (map->map_copy[i][j] != '1' && map->map_copy[i][j] != '0')
				show_error("Some elements are incorrect\n");
			j++;
		}
		i++;
	}
	if (map->player != 1 || map->exit != 1 || map->items == 0)
		show_error("Characters invalid\n");
}

void	map_read(t_map *map, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	map_ext(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		show_error("File error\n");
	map_dimensions(map, file);
	map->map_copy = ft_calloc(map->map_h, sizeof(char *));
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			map->map_copy[i++] = ft_strdup(line);
		if (map->map_w != ft_strlen(ft_strtrim(line, "\n")) && line)
			show_error("Map is not rectangular\n");
		free(line);
	}
	map_borders(map);
	map_characters(map);
	close(fd);
}
