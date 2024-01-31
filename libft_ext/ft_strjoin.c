/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 23:05:21 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/26 13:53:00 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	dst = ft_calloc(lens1 + lens2 + 1, sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[i++])
		ft_memcpy(dst, s1, lens1);
	while (s2[j++])
		ft_memcpy(lens1 + dst, s2, lens2);
	return (dst);
}
/*
int	main(void) {
	const char *str1 = "";
	const char *str2 = "";
	char *result;

	result = ft_strjoin(str1, str2);

	printf("Result: %s\n", result);
	free(result)

	return (0);
}*/