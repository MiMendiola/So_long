/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:29:32 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/03 18:01:31 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	ft_memset(str, '\0', len);
}
/*
#include <stdio.h>

int	main(void)
{
	char	buffer[10];
	char	buffer1[10];

	ft_bzero(buffer, sizeof(buffer));
	for (unsigned int i = 0; i < sizeof(buffer); i++)
		printf("buffer[%d] = %d\n", i, buffer[i]);
	bzero(buffer1, sizeof(buffer1));
	for (unsigned int i = 0; i < sizeof(buffer1); i++)
		printf("buffer1[%d] = %d\n", i, buffer1[i]);
}
*/