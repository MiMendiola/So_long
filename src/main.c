/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/09 15:17:53 by mmendiol         ###   ########.fr       */
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




void	sprite_creator(t_game *game, char *path, int posx, int posy)
{
	t_sprites	*img;
	
	img = malloc(sizeof(t_sprites));
	img->path = path;
	img->img_w = 52;
	img->img_h = 52;

	img = mlx_xpm_file_to_image(game->mlx, img->path, &img->img_w, &img->img_h);
	if (!img) {
		fprintf(stderr, "Error loading image from %s\n", img->path);
		exit(1);
	}
	
	mlx_put_image_to_window(game->mlx, game->win, img, posx, posy);
}


static void	sprite_characters(t_map *map, t_game *game, int posx, int posy)
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
				sprite_creator(game, "./textures/gogeta_wait.xpm", (posx + (j * 52)), (posy + (i * 52)));
			else if (map->map_copy[i][j] == 'E')
				sprite_creator(game, "./textures/gogeta_derecha_1.xpm", (posx + (j * 52)), (posy + (i * 52)));
			else if (map->map_copy[i][j] == 'C')
				sprite_creator(game, "./textures/gogeta_derecha_3.xpm", (posx + (j * 52)), (posy + (i * 52)));
			else if (map->map_copy[i][j] == '1')
				sprite_creator(game, "./textures/wall.xpm", (posx + (j * 52)), (posy + (i * 52)));
			else if (map->map_copy[i][j] == '0')
				sprite_creator(game, "./textures/suelo.xpm", (posx + (j * 52)), (posy + (i * 52)));
			j++;
		}
		i++;
	}
}




void	game_init(t_game *game, t_map *map, char *file)
{
	map_read(map, file);

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (map->map_w * 52), (map->map_h * 52), "Hello world!");

	// sprite_creator(game, "./textures/prueba.xpm", 0, 0);
	sprite_characters(map, game, 0, 0);
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
		game_init(game, map, av[1]);



		
	}
    return (0);
}


