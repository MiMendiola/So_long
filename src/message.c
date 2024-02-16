/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:08:57 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/16 15:01:26 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void    show_error(char *str)
{
    ft_putstr_fd(RED "ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(CLEAR, 2);
	exit (EXIT_FAILURE);
}

void	show_win(char *str)
{
	ft_putstr_fd(GREEN, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("", 2);
	ft_putstr_fd(CLEAR, 2);
	exit (EXIT_FAILURE);
}