/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_charger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:27:36 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/18 22:16:03 by mmendiol         ###   ########.fr       */
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

// void load_images(t_game *game)
// {
//     game->image->imges[3] = mlx_xpm_file_to_image(game->mlx, GOKUBASE3, &width, &height);
//     game->image->imges[4] = mlx_xpm_file_to_image(game->mlx, GOKUBASE4, &width, &height);
//     game->image->imges[5] = mlx_xpm_file_to_image(game->mlx, GOKUBASE5, &width, &height);
// }

void        frames_stay(t_game *game, int x, int y)
{
    if (game->frames <= 6)
    {
        sprite_creator(game, FLOOR, x, y);
        sprite_creator(game, GOKUBASE3, x, y);
    }
    else if (game->frames <= 12)
    {
        sprite_creator(game, FLOOR, x, y);
        sprite_creator(game, GOKUBASE4, x, y);
    }
    else if (game->frames <= 18)
    {
        sprite_creator(game, FLOOR, x, y);
        sprite_creator(game, GOKUBASE5, x, y);
    }
    else if (game->frames <= 24)
    {
        sprite_creator(game, FLOOR, x, y);
        sprite_creator(game, GOKUBASE4, x, y);
    }
    else
    {
        sprite_creator(game, FLOOR, x, y);
        sprite_creator(game, GOKUBASE3, x, y);
    }
    // if (game->frames <= 0)
    // {
    //     mlx_destroy_image(game->mlx, game->image->img);
    //     sprite_creator(game, GOKUBASE3, x, y);
    // }
    // else if (game->frames <= 10)
    // {
    //     mlx_destroy_image(game->mlx, game->image->img);
    //     sprite_creator(game, GOKUBASE4, x, y);
    // }
    // else if (game->frames <= 20)
    // {
    //     mlx_destroy_image(game->mlx, game->image->img);
    //     sprite_creator(game, GOKUBASE3, x, y);
    // }
    // else
    // {
    //     mlx_destroy_image(game->mlx, game->image->img);
    //     sprite_creator(game, GOKUBASE3, x, y);
    // }
}

void        frames_move_right(t_game *game, int x, int y)
{
    if (game->frames <= 40)
    {
        sprite_creator(game, FLOOR, x, y);
        sprite_creator(game, GOKUBASE11, x, y);
    }
    else if (game->frames <= 50)
    {
        sprite_creator(game, FLOOR, x, y);
        sprite_creator(game, GOKUBASE15, x, y);
    }
    else
    {
        sprite_creator(game, GOKUBASE3, x, y);
    }
}
