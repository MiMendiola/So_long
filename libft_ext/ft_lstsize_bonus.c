/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:04:36 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/02 21:09:30 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
/*
#include "ft_lstclear_bonus.c"
#include "ft_lstlast_bonus.c"
#include "ft_lstadd_back_bonus.c"
#include "ft_lstnew_bonus.c"
#include "ft_lstdelone_bonus.c"
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
int main() 
{
    t_list *list;
	list = NULL;
    ft_lstadd_back(&list, ft_lstnew("Element 1"));
    ft_lstadd_back(&list, ft_lstnew("Element 2"));
    ft_lstadd_back(&list, ft_lstnew("Element 3"));

    int size = ft_lstsize(list);
    printf("List size: %d\n", size);

	free(list);
    return 0;
}*/