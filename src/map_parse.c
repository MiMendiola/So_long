/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:45:16 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/12 21:13:24 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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

static	void	map_dimensions(t_map *map, char *file)
{
	int	fd;
	int	height;
	int	width;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		show_error("File error\n");
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
	map->player = 0;
	map->exit = 0;
	map->items = 0;
}

static void	map_borders(t_map *map)
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
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] && map->map[i][j] != '\n')
		{
			if (map->map[i][j] == 'P')
				map->player += 1;
			else if (map->map[i][j] == 'E')
				map->exit += 1;
			else if (map->map[i][j] == 'C')
				map->items += 1;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0')
				show_error("Some elements are incorrect\n");
			j++;
		}
		i++;
	}
	map->balls = map->items; 
	if (map->player != 1 || map->exit != 1 || map->balls == 0 || map->balls > 7)
		show_error("Characters invalid\n");
}

void	map_read(t_map *map, char *file)
{
	int		fd;
	int		i;
	char 	*cmap;
	char 	*cpy_aux;
	char	*line;

	i = -1;
	map_ext(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		show_error("File error\n");
	map_dimensions(map, file);
	cmap = ft_strdup("");
	while (++i < map->map_h && line != NULL)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
            free(line);
            free(cmap);
            show_error("Map contains an unexpected newline\n");
        }
		cpy_aux = ft_strdup(cmap);
		free(cmap);
		cmap = ft_strjoin(cpy_aux, line);
		free(cpy_aux);
		free(line);
	}
	if (cmap[0] == '\n' || cmap[ft_strlen(cmap) - 1] == '\n')
		show_error("Check the first or last line of your map\n");
	map->map = ft_split(cmap, '\n');
	free(cmap);
	map_borders(map);
	map_characters(map);
	close(fd);
}
