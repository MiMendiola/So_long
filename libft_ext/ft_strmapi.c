/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:03:28 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/29 18:59:15 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char	my_function(unsigned int index, char c) {
	if (index % 2 == 0) {
		if (c >= 'a' && c <= 'z') {
			return (c - ('a' - 'A'));
		}
	} else {
		if (c >= 'A' && c <= 'Z') {
			return (c + ('a' - 'A'));
		}
	}
	return (c);
}

int	main(void)
{
	const char *input = "Hello, World!";

	char *result = ft_strmapi(input, my_function);

	if (result != NULL) {
		printf("Resultado: %s\n", result);
		free(result);
	}

	return (0);
}*/