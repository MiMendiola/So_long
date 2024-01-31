/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:40:10 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/02 20:43:12 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	print_char_and_index(unsigned int index, char *c) 
{
	printf("I: %u, Char: %c\n", index, *c);
}

int	main(void) {
	char str[] = "Hola, Mundo!";

	printf("Cad: %s\n", str);
	ft_striteri(str, print_char_and_index);

	return (0);
}
*/