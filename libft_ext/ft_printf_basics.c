/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:19:18 by mmendiol          #+#    #+#             */
/*   Updated: 2024/01/31 17:04:40 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr(int nb)
{
	unsigned int	num;
	int				counter;

	num = nb;
	counter = 0;
	if (nb < 0)
	{
		num *= -1;
		counter += ft_putchar('-');
	}
	if (num > 9)
	{
		counter += ft_putnbr(num / 10);
		counter += ft_putchar((num % 10) + '0');
	}
	else
		counter += ft_putchar(num + '0');
	return (counter);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	num;
	int				counter;

	num = nb;
	counter = 0;
	if (num > 9)
	{
		counter += ft_putnbr_unsigned(num / 10);
		counter += ft_putchar((num % 10) + '0');
	}
	else
		counter += ft_putchar(num + '0');
	return (counter);
}
