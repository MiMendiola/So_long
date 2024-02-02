/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/02 18:29:13 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_ext/libft.h"
#include "./so_long.h"
#include "./libft_ext/ft_putstr_fd.c"
#include "./libft_ext/get_next_line.c"
#include "./libft_ext/get_next_line_utils.c"

void    map_ext(const char *str, const char *to_find)
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

void	check_borders()
{
	
}

void	read_map(t_map **map,char *file)
{
	int		fd;
	int		i;
	char	*line;
	
	i = 0;
	map_ext(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	free(line);
	while (line)
	{
		(*map)->map_copy[i] = get_next_line(fd);
		if (!line)
			exit(EXIT_FAILURE);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);	
}


// int	main(int ac, char *av[])
// {
// 	const char	*p;

// 	p = "hola.ber.ber";
// 	map_ext(p, ".ber");
// 	return (0);
// }

int main(int ac, char *av[])
{	
	t_map *map = NULL;
	// int i = 0;
	
	(void)av;
    if (ac < 1)
        return 0;
    else
	{
		read_map(&map ,"./maps/map1.ber");
		// while (i < 2)
		// {
		// 	printf("%s", map->map_copy[i]);
		// 	i++;
			
		// }
	}
    return (0);
}


