/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:42:53 by lolee             #+#    #+#             */
/*   Updated: 2019/05/26 20:38:42 by lolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstmap_del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	if (!lst)
		return (0);
	tail = 0;
	tmp = 0;
	while (lst)
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		if (!tmp)
			break ;
		tmp = f(tmp);
		if (tail)
			tail->next = tmp;
		else
			head = tmp;
		tail = tmp;
		lst = lst->next;
	}
	if (!tmp)
		ft_lstdel(&head, ft_lstmap_del);
	return (head);
}
