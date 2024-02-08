/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/08 19:46:54 by mmendiol         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	game_init(t_game *game, t_map *map, char *file)
{
	t_data	img;
	
	map_read(map, file);

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (map->map_w * 52), (map->map_h * 52), "Hello world!");
	
	
	
	img.img = mlx_new_image(game->mlx, 52, 52);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 20, 20, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
	mlx_loop(game->mlx);
	
}

int main(int ac, char *av[])
{	
	t_map *map;
	t_game *game;

	map = malloc(sizeof(t_map));
	game = malloc(sizeof(t_game));
    if (ac != 2) {
		show_error("Bad arguments\n");
	}
    else
	{
		// map_read(map, av[1]);
		game_init(game, map, av[1]);
		// void	*mlx;
		// void	*mlx_win;

		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
		// mlx_loop(mlx);
		// while (i < 2)
		// {
		// 	printf("%s", map->map_copy[i]);
		// 	i++;
			
		// }
	}
    return (0);
}


