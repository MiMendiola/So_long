/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:58:53 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/28 19:03:23 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (len > i)
	{
		s[i] = (unsigned char)value;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	arr[5];
	int	arr1[5];

	ft_memset(arr, 5, sizeof(arr));
	for (int i = 0; i < 5; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	memset(arr1, 5, sizeof(arr1));
	for (int i = 1; i < 5; i++) {
		printf("arr[%d] = %d\n", i, arr1[i]);
	}
}
*/