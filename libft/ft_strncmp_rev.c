/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp_rev.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 14:16:35 by katherine     #+#    #+#                 */
/*   Updated: 2021/03/15 15:26:56 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp_rev(const char *str1, const char *str2, size_t len)
{
	unsigned int	i1;
	unsigned int	i2;

	if (!(str1 || str2))
		return (0);
	if (!(str1 && str2))
		return (-1);
	if (str1 == str2)
		return (0);
	i1 = ft_strlen(str1) - 1;
	i2 = ft_strlen(str2) - 1;
	while ((str1[i1] || str2[i2]) && len > 0)
	{
		if (str1[i1] != str2[i2])
			return (str1[i1] - str2[i2]);
		i1--;
		i2--;
		len--;
	}
	return (0);
}
