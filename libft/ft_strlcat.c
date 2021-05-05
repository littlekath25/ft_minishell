/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:42:00 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/16 12:07:42 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	n;

	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (len == 0)
		return (slen);
	else if (dlen >= len)
		return (len + slen);
	n = len - dlen - 1;
	while (i < n && src[i])
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
