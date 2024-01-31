/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:33:25 by mmendiol          #+#    #+#             */
/*   Updated: 2024/01/31 16:33:57 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	character;

	i = 0;
	character = (unsigned char)c;
	if (character == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == character)
			return ((char *)(i + s));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	p[];

	p[] = "Hola Mundo";
	printf("Funcion: %s", ft_strchr(p, 'a'));
	return (0);
}
*/