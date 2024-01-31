/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:41:14 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/02 21:10:09 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
/*
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
int main() {
	
    t_list *list;
	list = ft_lstnew("Element");

    printf("Content: %s\n", (char *)(list->content));

    return 0;
}*/