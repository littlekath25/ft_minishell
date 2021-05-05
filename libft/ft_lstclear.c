/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 14:22:49 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/05 15:32:17 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	ptr = *lst;
	if (!lst || !*lst || !del)
		return ;
	while (lst && *lst)
	{
		ptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}
