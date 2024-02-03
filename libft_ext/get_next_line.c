/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:28 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/03 17:01:55 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char **to_free)
{
	if (*to_free == NULL)
		return ;
	free(*to_free);
	*to_free = NULL;
}

void	relocate_line(char **str_static, char **front)
{
	int		i;
	int		j;
	char	*back;

	i = 0;
	j = -1;
	back = NULL;
	if (!*str_static || str_static[0] == '\0')
		*front = NULL;
	while ((*str_static)[i] != '\0' && (*str_static)[i] != '\n')
		i++;
	i++;
	*front = ft_substr_gnl(*str_static, 0, i);
	if (!*front)
		return ;
	back = *str_static;
	*str_static = ft_substr_gnl(*str_static, i, (ft_strlen_gnl(*str_static) - i));
	free(back);
}

// Is going to read till we have a \n in our static
char	*read_till_find(int fd, char *str_static)
{
	int		nb_bytes;
	char	new_read[BUFFER_SIZE + 1];

	nb_bytes = 1;
	while (!ft_strchr_gnl(str_static, '\n') && nb_bytes != 0)
	{
		nb_bytes = read(fd, new_read, BUFFER_SIZE);
		if (nb_bytes < 0)
			return (free(&str_static), NULL);
		if (nb_bytes == 0)
			break ;
		new_read[nb_bytes] = '\0';
		str_static = ft_strjoin_gnl(str_static, new_read);
	}
	return (str_static);
}

// This function is going to return you the front part to write it down
char	*get_next_line(int fd)
{
	static char	*main_str;
	char		*print;

	print = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free_all(&main_str);
		return (NULL);
	}
	main_str = read_till_find(fd, main_str);
	if (!main_str)
	{
		free_all(&main_str);
		return (NULL);
	}
	relocate_line(&main_str, &print);
	return (print);
}
