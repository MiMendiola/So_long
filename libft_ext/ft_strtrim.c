/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:02:13 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/03 22:39:32 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	if (i > j)
		return (ft_strdup(""));
	else
		return (ft_substr(s1, i, j - i + 1));
}
/*
#include "ft_strchr.c"
#include "ft_strdup.c"
#include "ft_strlen.c"
#include "ft_substr.c"
#include "ft_calloc.c"
#include "ft_memset.c"
#include "ft_bzero.c"
int	main(void)
{
	char s[] = "hhhhhhhhhhhhhxxxxxxholaololoxxxxxxlololloloooaaaaaaaaa";

	printf("%s\n", ft_strtrim(s, "hola"));
	return (0);
}*/