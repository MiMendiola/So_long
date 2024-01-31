/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:54:29 by mmendiol          #+#    #+#             */
/*   Updated: 2023/09/28 19:54:47 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*
#include "ft_lstclear_bonus.c"
#include "ft_lstlast_bonus.c"
#include "ft_lstnew_bonus.c"
#include "ft_lstadd_front_bonus.c"
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
int main() {
	t_list *list;
    list = NULL;

    char *element1 = strdup("Element 1");
    char *element2 = strdup("Element 2");
    char *element3 = strdup("Element 3");

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    node1->content = element1;
    node2->content = element2;
    node3->content = element3;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    list = node1;

    ft_lstclear(&list, free); 

    printf("Lista nueva:\n");
    while (list)
    {
        printf("%s\n", (char *)(list->content));
        list = list->next;
    }

    return 0;
}*/