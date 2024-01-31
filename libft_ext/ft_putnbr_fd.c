/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:36:18 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/29 19:43:13 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int nbr)
{
	int	cnt;

	cnt = 0;
	while (nbr)
	{
		nbr /= 10;
		cnt++;
	}
	return (cnt);
}

static void	calc(unsigned int nbr, int len, int fd)
{
	int	n;

	while (len--)
		nbr /= 10;
	n = (nbr % 10) + '0';
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	num;
	int				size;

	if (nb < 0)
	{
		num = nb * -1;
		write(fd, "-", 1);
	}
	else
		num = nb;
	if (num == 0)
		write(fd, "0", 1);
	size = counter(num);
	while (size--)
		calc(num, size, fd);
}
/*
#include <stdio.h>

int	main(void)
{
	ft_putnbr(456);
	return (0);
}*/