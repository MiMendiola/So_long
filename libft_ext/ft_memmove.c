/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:44:14 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/24 23:27:01 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if ((d > s) && (s + len > d))
	{
		while (len--)
			d[len] = s[len];
	}
	else
		ft_memcpy(d, s, len);
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "Hello World";
// 	char	dest[13];
// 	char	dest1[13];

// 	ft_memmove(dest, src, 13);
// 	memmove(dest1, src, 13);
// 	printf("Mia: %s\n", dest);
// 	printf("Orig: %s\n", dest1);

// 	// char buffer[20] = "Hello, World!";
//     // char *src = buffer + 6;  // Puntero a la "W"
//     // char *dest = buffer + 1; // Puntero a la espacio después de la "H"
//     // size_t length = 7;       // Longitud de datos a copiar

//     // printf("Original: %s\n", buffer);

//     // ft_memmove(dest, src, length);

//     // printf("After ft_memmove: %s\n", buffer);
// 	return (0);
// }
