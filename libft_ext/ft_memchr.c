/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:07:36 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/26 13:01:18 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned int	i;
	unsigned char	character;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	character = (unsigned char)c;
	while (len > i)
	{
		if (str[i] == character)
			return (i + (void *)s);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[];

	s[] = "Hola Mundo";
	printf("MIO: %s\n", ft_memchr(s, 'o', 4));
	printf("ORI: %s", memchr(s, 'o', 4));
	return (0);
}
*/