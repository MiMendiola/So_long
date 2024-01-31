/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:34 by mmendiol          #+#    #+#             */
/*   Updated: 2024/01/31 16:34:32 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

/*	Here we will check if in our string s we have the character that we pass
 *	1 is that the character is there
 *	0 is the character is not in the str	*/
int	ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i++] == (char)c)
			return (1);
	}
	return (0);
}

char	*ft_strjoin_gnl(char *main, char *buffer)
{
	int		i;
	int		j;
	int		k;
	char	*dst;

	i = 0;
	j = 0;
	k = 0;
	if (!main)
	{
		main = malloc(sizeof(char) * 1);
		main[0] = '\0';
	}
	if (!main)
		return (NULL);
	dst = malloc((ft_strlen(main) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (main && main[j])
		dst[i++] = main[j++];
	while (buffer && buffer[k])
		dst[i++] = buffer[k++];
	dst[i] = '\0';
	free(main);
	return (dst);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	maxlen;
	char	*dst;

	i = 0;
	if (!s)
		return (0);
	maxlen = ft_strlen(s);
	if (start >= maxlen)
		return (NULL);
	if (len > maxlen - start)
		len = maxlen - start;
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (len > i && start < maxlen)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
