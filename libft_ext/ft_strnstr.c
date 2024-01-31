/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:57:53 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/26 13:24:22 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && (i < len))
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return (i + (char *)str);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[];
	char	f[];

	s[] = "lorem ipsum dol sit dolor amet";
	f[] = "dolor";
	printf("Mio: %s\n", ft_strnstr(s,f,25));
	printf("Ori: %s", strnstr(s,f,25));
	return (0);
}
*/