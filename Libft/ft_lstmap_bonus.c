/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:13:56 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/21 21:42:59 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delete_clear(t_list *head, void (*del)(void *), void *tmp)
{
	del(tmp);
	ft_lstclear(&head, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	void	*tmp;

	new = NULL;
	head = new;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		if (tmp == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new = ft_lstnew(tmp);
		if (new == NULL)
		{
			delete_clear(head, del, tmp);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
