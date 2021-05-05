/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 16:43:42 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/14 19:49:05 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*deflist;

	if (!lst || !f)
		return (NULL);
	deflist = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			if (deflist)
				ft_lstclear(&deflist, (*del));
			return (NULL);
		}
		ft_lstadd_back(&deflist, new);
		lst = lst->next;
	}
	return (deflist);
}
