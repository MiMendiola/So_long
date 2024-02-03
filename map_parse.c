/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/03 19:20:10 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_ext/libft.h"
#include "./so_long.h"
#include "./libft_ext/ft_putstr_fd.c"
#include "./libft_ext/ft_strjoin.c"
#include "./libft_ext/ft_memcpy.c"
#include "./libft_ext/ft_calloc.c"
#include "./libft_ext/ft_strlen.c"
#include "./libft_ext/ft_strtrim.c"
#include "./libft_ext/ft_strdup.c"
#include "./libft_ext/ft_strchr.c"
#include "./libft_ext/ft_substr.c"
#include "./libft_ext/ft_bzero.c"
#include "./libft_ext/ft_memset.c"
#include "./libft_ext/get_next_line.c"
#include "./libft_ext/get_next_line_utils.c"

static	void    map_ext(const char *str, const char *to_find)
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
            {
				ft_putstr_fd("Guardar el nombre del archivo en estructura\n", 1);
                return;
            }
			j++;
		}
		i++;
	}
    ft_putstr_fd("Please, check the map extension\n", 1);
    exit(EXIT_FAILURE);
}

static	void	map_dimensions(t_map *map, char *file)
{
	int	fd;
	int	height;
	int	width;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	width = ft_strlen(get_next_line(fd));
	height = 1;
	while (get_next_line(fd))
		height++;
	close(fd);
	map->map_h = height;
	map->map_w = width - 1;
}

void	check_borders()
{
	
}

static	void	map_read(t_map *map,char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	map_ext(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	map_dimensions(map, file);
	map->map_copy = ft_calloc(map->map_h, sizeof(char *));
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			map->map_copy[i++] = ft_strdup(line);
		if (map->map_w != ft_strlen(ft_strtrim(line, "\n")) && line)
			exit(EXIT_FAILURE);
		free(line);
	}

	int j = 0;
	while (j < map->map_h)
	{
		printf("%s", map->map_copy[j]);
		j++;
	}
	close(fd);	
}

int main(int ac, char *av[])
{	
	t_map *map;
	map = malloc(sizeof(t_map));
	
	(void)av;
    if (ac < 1)
        return 0;
    else
	{
		map_read(map ,"./maps/map1.ber");
		// while (i < 2)
		// {
		// 	printf("%s", map->map_copy[i]);
		// 	i++;
			
		// }
	}
    return (0);
}


