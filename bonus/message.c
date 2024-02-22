/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:08:57 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/22 21:18:56 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, "Steps:");
	mlx_string_put(game->mlx, game->win, 75, 20, 0xFFFFFF, moves);
	free(moves);
}

void	show_error(char *str)
{
	ft_putstr_fd(RED "ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(CLEAR, 2);
	exit(EXIT_FAILURE);
}

void	show_win(void)
{
	ft_putstr_fd(GREEN, 2);
	ft_putstr_fd("==============================\n", 2);
	ft_putstr_fd(WINS, 2);
	ft_putstr_fd("==============================\n", 2);
	ft_putstr_fd("", 2);
	ft_putstr_fd(CLEAR, 2);
	exit(EXIT_FAILURE);
}

void	show_lose(void)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("==============================\n", 2);
	ft_putstr_fd(LOSE, 2);
	ft_putstr_fd("==============================\n", 2);
	ft_putstr_fd("", 2);
	ft_putstr_fd(CLEAR, 2);
	exit(EXIT_FAILURE);
}
