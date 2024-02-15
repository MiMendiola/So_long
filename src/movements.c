/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:43:29 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/15 18:45:55 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	move_player_up(t_game *game)
{
	int	posx;
	int	posy;

	posx = game->player.posx;
	posy = game->player.posy;
	if (game->map_check[posy - 1][posx] != '1')
	{
		if (game->map_check[posy - 1][posx] == 'C')
		{
			game->items--;
			if (game->items == 0)
			{
				game->map_check[game->posymap][game->posxmap] = 'E';
				sprite_exit(game, game->posymap, game->posxmap);
			}
			printf("Items: %d\n", game->items);
		}
		if (game->map_check[posy - 1][posx] == 'E'
			&& game->items == 0)
			exit(EXIT_SUCCESS);
			
		game->map_check[posy][posx] = '0';
		game->map_check[posy - 1][posx] = 'P';
		game->player.posy--;
		game->player.steps++;
		sprite_creator(game, "./textures/suelo.xpm", posy, posx);
		sprite_creator(game, "./textures/suelo.xpm", posy - 1, posx);
		sprite_creator(game, "./textures/goku_base/goku_base.xpm", posy - 1, posx);
	}
}

void	move_player_down(t_game *game)
{
	int	posx;
	int	posy;

	posx = game->player.posx;
	posy = game->player.posy;
	if (game->map_check[posy + 1][posx] != '1')
	{
		if (game->map_check[posy + 1][posx] == 'C')
		{
			game->items--;
			if (game->items == 0)
			{
				game->map_check[game->posymap][game->posxmap] = 'E';
				sprite_exit(game, game->posymap, game->posxmap);
			}
			printf("Items: %d\n", game->items);
		}
		if (game->map_check[posy + 1][posx] == 'E'
			&& game->items == 0)
			exit(EXIT_SUCCESS);
			
		game->map_check[posy][posx] = '0';
		game->map_check[posy + 1][posx] = 'P';
		game->player.posy++;
		game->player.steps++;
		sprite_creator(game, "./textures/suelo.xpm", posy, posx);
		sprite_creator(game, "./textures/suelo.xpm", posy + 1, posx);
		sprite_creator(game, "./textures/goku_base/goku_base.xpm", posy + 1, posx);
		printf("S o Arrow down, Posicion: ");
		printf("%d\n", game->player.posy);
	}
}

void	move_player_left(t_game *game)
{
	int	posx;
	int	posy;

	posx = game->player.posx;
	posy = game->player.posy;
	if (game->map_check[posy][posx - 1] != '1')
	{
		if (game->map_check[posy][posx - 1] == 'C')
		{
			game->items--;
			if (game->items == 0)
			{
				game->map_check[game->posymap][game->posxmap] = 'E';
				sprite_exit(game, game->posymap, game->posxmap);
			}
			printf("Items: %d\n", game->items);
		}
		if (game->map_check[posy][posx - 1] == 'E'
			&& game->items == 0)
			exit(EXIT_SUCCESS);
		game->map_check[posy][posx] = '0';
		game->map_check[posy][posx - 1] = 'P';
		game->player.posx--;
		game->player.steps++;
		sprite_creator(game, "./textures/suelo.xpm", posy, posx);
		sprite_creator(game, "./textures/suelo.xpm", posy, posx - 1);
		sprite_creator(game, "./textures/goku_base/goku_base.xpm", posy, posx - 1);
		printf("A o Arrow left, Posicion: ");
		printf("%d\n", game->player.posy);
	}
}

void	move_player_right(t_game *game)
{
	int	posx;
	int	posy;

	posx = game->player.posx;
	posy = game->player.posy;
	if (game->map_check[posy][posx + 1] != '1')
	{
		if (game->map_check[posy][posx + 1] == 'C')
		{
			game->items--;
			if (game->items == 0)
			{
				game->map_check[game->posymap][game->posxmap] = 'E';
				sprite_exit(game, game->posymap, game->posxmap);
			}
			printf("Items: %d\n", game->items);
		}
		if (game->map_check[posy][posx + 1] == 'E'
			&& game->items == 0)
			exit(EXIT_SUCCESS);
		game->map_check[posy][posx] = '0';
		game->map_check[posy][posx + 1] = 'P';
		game->player.posx++;	
		game->player.steps++;
        sprite_creator(game, "./textures/suelo.xpm", posy, posx);
		sprite_creator(game, "./textures/suelo.xpm", posy, posx + 1);
        sprite_creator(game, "./textures/goku_base/goku_base.xpm", posy, posx + 1);
		
		printf("D o Arrow right, Posicion: ");
		printf("%d\n", game->player.posx);
	}
}