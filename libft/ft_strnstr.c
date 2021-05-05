/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:42:14 by kfu           #+#    #+#                 */
/*   Updated: 2020/12/02 14:28:48 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	nlen;
	size_t	i;

	i = 0;
	nlen = ft_strlen(small);
	if (!*small)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == small[0] && len >= i + nlen)
		{
			if (ft_strncmp(&big[i], &small[0], nlen) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
