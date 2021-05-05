/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 14:08:32 by kfu           #+#    #+#                 */
/*   Updated: 2020/12/02 12:18:45 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*tmp;
	size_t				i;
	unsigned int		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len && start + i <= slen)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
