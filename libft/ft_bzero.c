/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:41:08 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/05 15:30:46 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *buf, size_t len)
{
	unsigned char	*s;
	size_t			i;

	s = buf;
	i = 0;
	while (i < len)
	{
		s[i] = '\0';
		i++;
	}
}
