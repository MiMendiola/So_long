/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:01:06 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/03 18:00:28 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	size_sign;

	i = 0;
	n = 0;
	size_sign = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			size_sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += (str[i] - '0');
		i++;
	}
	if (size_sign == 1)
		n *= -1;
	return (n);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str1 = "--54";
	char *str2 = "   			a	+48";
	char *str3 = "-47";
	char *str4 = "+47";

	printf("%d\n", ft_atoi(str1));
	printf("%d\n", atoi(str1));
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", atoi(str2));
	printf("%d\n", ft_atoi(str3));
	printf("%d\n", atoi(str3));
	printf("%d\n", ft_atoi(str4));
	printf("%d\n", atoi(str4));
	return (0);
}
*/