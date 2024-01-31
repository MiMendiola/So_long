/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:10:31 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/03 19:17:27 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(str);
	j = ft_strlen(dest);
	k = 0;
	if (dstsize < j || dstsize == 0)
		return (i + dstsize);
	while (str[k] && j + k < dstsize - 1)
	{
		dest[j + k] = str[k];
		k++;
	}
	dest[j + k] = '\0';
	return (j + i);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[50];
	char	src[];
	char	dest2[];
	char	src2[];

	dest[50] = "lorem ipsum dolor sit amet";
	src[] = "hellofri";
	dest2[] = "lorem ipsum dolor sit amet";
	src2[] = "hellofri";
	printf("Mia: %zu %s\n", ft_strlcat(dest,src,15), dest);
	printf("Original: %lu %s\n", strlcat(dest2,src2,15), dest2);
	return (0);
}
*/
