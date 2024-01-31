/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendiol <mmendiol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:12:43 by mmendiol          #+#    #+#             */
/*   Updated: 2023/10/03 22:17:40 by mmendiol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;
	void	*res_f;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		res_f = f(lst->content);
		tmp = ft_lstnew(res_f);
		if (!tmp)
		{
			ft_lstclear(&result, del);
			del(res_f);
			return (NULL);
		}
		ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
/*
#include "ft_lstclear_bonus.c"
#include "ft_lstlast_bonus.c"
#include "ft_lstnew_bonus.c"
#include "ft_lstdelone_bonus.c"
#include "ft_lstadd_back_bonus.c"
#include "ft_strdup.c"
#include "ft_strlen.c"
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
void *duplicate_string(void *content)
{
    char *original = (char *)content;
    return ft_strdup(original);
}

int main()
{
    t_list *lst = NULL;
    ft_lstadd_back(&lst, ft_lstnew("Hola"));
    ft_lstadd_back(&lst, ft_lstnew("Mundo"));
    ft_lstadd_back(&lst, ft_lstnew("123"));

    t_list *duplicated = ft_lstmap(lst, duplicate_string, free);

    printf("Lista duplicada:\n");
    t_list *current = duplicated;
    while (current)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    ft_lstclear(&duplicated, free);

    return 0;
}*/