/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:55:28 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/21 10:03:35 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (len > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	char	src[];
	char	dest[20];
	char	dest1[20];

	src[] = "\0";
	ft_memcpy(dest, src, 13);
	memcpy(dest1, src, 13);
	printf("Mia: %s\n", dest);
	printf("Orig: %s\n", dest1);
	return (0);
}
*/
