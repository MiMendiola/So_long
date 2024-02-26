/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_covers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:35:06 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/26 14:07:28 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sprite_covers(t_game *game, int posx)
{
	int	x;
	int	y;

	x = (ft_strlen(game->map_check[0]) / 2 - 1);
	y = 0;
	while (game->map_check[y])
		y++;
	y = (y / 2) - 1;
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->inits->cv1, posx
		* (PIXELS * 3.62), y * PIXELS);
}
