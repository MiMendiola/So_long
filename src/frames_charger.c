/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_charger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:27:36 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/19 20:01:56 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void        frames_first_animation(t_game *game)
{
    if (game->frames <= 10)
    {
        sprite_creator(game, GOKUBASE, game->player.posy, game->player.posx);
    }
    else if (game->frames <= 12)
    {
        sprite_creator(game, FLOOR, game->player.posy, game->player.posx);
        sprite_creator(game, GOKUBASE1, game->player.posy, game->player.posx);
    }
    else if (game->frames <= 15)
    {
        sprite_creator(game, FLOOR, game->player.posy, game->player.posx);
        sprite_creator(game, GOKUBASE1, game->player.posy, game->player.posx);
    }
    else if (game->frames <= 20)
    {
        sprite_creator(game, FLOOR, game->player.posy, game->player.posx);
        sprite_creator(game, GOKUBASE2, game->player.posy, game->player.posx);
    }
    else
    {
        sprite_creator(game, FLOOR, game->player.posy, game->player.posx);
        sprite_creator(game, GOKUBASE3, game->player.posy, game->player.posx);
    }
}


void        frames_stay(t_game *game, int x, int y)
{
    if (game->frames <= 6)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->initS->floo, x, y);
        mlx_put_image_to_window(game->mlx, game->win, game->initS->gkb, x, y);
    }
    else if (game->frames <= 12)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->initS->floo, x, y);
        mlx_put_image_to_window(game->mlx, game->win, game->initS->gk4, x, y);

    }
    else if (game->frames <= 18)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->initS->floo, x, y);
        mlx_put_image_to_window(game->mlx, game->win, game->initS->gk5, x, y);
    }
    else if (game->frames <= 24)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->initS->floo, x, y);
        mlx_put_image_to_window(game->mlx, game->win, game->initS->gk4, x, y);
    }
    else
    {
        mlx_put_image_to_window(game->mlx, game->win, game->initS->floo, x, y);
        mlx_put_image_to_window(game->mlx, game->win, game->initS->gkb, x, y);
    }
}
