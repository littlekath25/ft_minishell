/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:42:04 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/15 12:04:37 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	slen;

	if (!src)
		return (0);
	slen = ft_strlen(src);
	if (len >= slen + 1)
		ft_memcpy(dest, src, slen + 1);
	else if (len > 0)
	{
		ft_memcpy(dest, src, len - 1);
		dest[len - 1] = '\0';
	}
	return (slen);
}
