/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:43:29 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/18 19:37:59 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	movement_goku_base(t_game *game, int posx, int posy)
{
	if (game->map_check[posy][posx] == 'C')
			game->items--;
	if (game->map_check[posy][posx] == 'E' && game->items == 0)
		show_win(WINS);
	game->map_check[posy][posx] = '0';
	game->map_check[posy][posx] = 'P';
	game->steps++;
}

void	move_player_up(t_game *game)
{
	int	posx;
	int	posy;

	posx = game->player.posx;
	posy = game->player.posy;
	if (game->map_check[posy - 1][posx] != '1')
	{
		game->map_check[posy][posx] = '0';
		movement_goku_base(game, posx, posy - 1);
		game->player.posy--;
		sprite_creator(game, FLOOR, posy, posx);
		sprite_creator(game, FLOOR, posy - 1, posx);
		sprite_creator(game, GOKUBASE3, posy - 1, posx);
		ft_printf("Moves: %d\n", game->steps);
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
		game->map_check[posy][posx] = '0';
		movement_goku_base(game, posx, posy + 1);
		game->player.posy++;
		sprite_creator(game, FLOOR, posy, posx);
		sprite_creator(game, FLOOR, posy + 1, posx);
		sprite_creator(game, GOKUBASE3, posy + 1, posx);
		ft_printf("Moves: %d\n", game->steps);
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
		game->map_check[posy][posx] = '0';
		movement_goku_base(game, posx - 1, posy);
		game->player.posx--;
		sprite_creator(game, FLOOR, posy, posx);
		sprite_creator(game, FLOOR, posy, posx - 1);
		sprite_creator(game, GOKUBASE3, posy, posx - 1);
		ft_printf("Moves: %d\n", game->steps);
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
		game->map_check[posy][posx] = '0';
		movement_goku_base(game, posx + 1, posy);
		game->player.posx++;
		sprite_creator(game, FLOOR, posy, posx);
		sprite_creator(game, FLOOR, posy, posx + 1);
		sprite_creator(game, GOKUBASE3, posy, posx + 1);
		ft_printf("Moves: %d\n", game->steps);
	}
	
}
