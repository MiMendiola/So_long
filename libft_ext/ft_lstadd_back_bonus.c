/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:48:46 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/02 20:57:07 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*result;

	if (*lst)
	{
		result = ft_lstlast(*lst);
		result->next = new;
	}
	else
		*lst = new;
}
/*
#include "ft_lstclear_bonus.c"
#include "ft_lstlast_bonus.c"
#include "ft_lstnew_bonus.c"
#include "ft_lstdelone_bonus.c"
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
int main() {
    t_list *myList;
	myList = NULL;
	
    t_list *element1 = ft_lstnew("Element 1");
    t_list *element2 = ft_lstnew("Element 2");
    t_list *element3 = ft_lstnew("Element 3");

    ft_lstadd_back(&myList, element1);
    ft_lstadd_back(&myList, element2);
    ft_lstadd_back(&myList, element3);

    while (myList) {
        printf("%s\n", (char *)(myList->content));
        myList = myList->next;
    }
	
    ft_lstclear(&myList, NULL);

    return 0;
}*/