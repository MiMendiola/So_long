/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:05:43 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/26 13:02:55 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	character;

	i = ft_strlen(s) - 1;
	character = (unsigned char)c;
	if (character == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (i >= 0)
	{
		if (s[i] == character)
			return ((char *)(i + s));
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	p[];

	p[] = "bonjour";
	printf("Dest: %s\n", ft_strrchr(p + 2, 'b'));
	printf("ORI: %s", strrchr(p + 2, 'b'));
	return (0);
}
*/