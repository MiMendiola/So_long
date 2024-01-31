/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:00:00 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/03 16:51:47 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;

	while (*lst)
	{
		list = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = list;
	}
}
/*
#include "ft_lstlast_bonus.c"
#include "ft_lstadd_front_bonus.c"
#include "ft_lstnew_bonus.c"
#include "ft_lstdelone_bonus.c"
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"

int main() {
    t_list *list;
	list = NULL;

    t_list *element1 = ft_lstnew("Element 1");
    t_list *element2 = ft_lstnew("Element 2");
    t_list *element3 = ft_lstnew("Element 3");

    ft_lstadd_front(&list, element3);
    ft_lstadd_front(&list, element2);
    ft_lstadd_front(&list, element1);

    while (list) {
        printf("%s\n", (char *)(list->content));
        list = list->next;
    }

	ft_lstclear(&list, free);

	while (list == NULL) 
		return(printf("Vacio\n"));

    return 0;
}*/