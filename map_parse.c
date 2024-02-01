/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:05:42 by mmendiol          #+#    #+#             */
/*   Updated: 2024/02/01 22:06:50 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_ext/libft.h"
#include "./libft_ext/ft_strlen.c"
#include "./libft_ext/ft_putstr_fd.c"

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t			i;
// 	unsigned char	character;

// 	i = 0;
// 	character = (unsigned char)c;
// 	if (character == '\0')
// 		return ((char *)&s[ft_strlen(s)]);
// 	while (s[i])
// 	{
// 		if (s[i] == character)
//         {
//             if (s[i + 1] == '\0')
// 			    return ((char *)(s));
//             else
//                 return ("The map extension is not valid");
//         }
// 		i++;
// 	}
// 	return (NULL);
// }

void    map_ext(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (str[i + j + 1] == '\0' && to_find[j + 1] == '\0')
            {
				ft_putstr_fd("Guardar el nombre del archivo en estructura", 1);
                return;
            }
			j++;
		}
        // Este codigo es para que el .ber.ber no funcione
        // if (ft_strlen(to_find) == j)
        // {
        //     ft_putstr_fd("The map extension is not valid", 1);
        //     return;
        // }
		i++;
	}
    //  EXIT te corta directammente el programa entero
    ft_putstr_fd("Please, check the map extension", 1);
    exit(EXIT_FAILURE);
}


int	main(int ac, char *av[])
{
	const char	*p;

	p = "hola.ber";
	map_ext(p, ".ber");
	return (0);
}

// int main(int ac, char *av[])
// {
//     if (ac != 2)
//         return 0;
//     else
//         printf("%s", av[0]);
//     return (0);
// }