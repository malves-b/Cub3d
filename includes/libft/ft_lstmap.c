/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:36:26 by pemirand          #+#    #+#             */
/*   Updated: 2025/02/13 16:05:15 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_list	*new_node_or_clear(t_list *lst, t_list **head,
				void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*set;

	set = f(lst->content);
	new = ft_lstnew(set);
	if (!new)
	{
		del(set);
		ft_lstclear(head, del);
		return (NULL);
	}
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*actual;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		new = new_node_or_clear(lst, &head, f, del);
		if (!new)
			return (NULL);
		if (!head)
		{
			head = new;
			actual = head;
		}
		else
		{
			actual->next = new;
			actual = actual->next;
		}
		lst = lst->next;
	}
	return (head);
}
