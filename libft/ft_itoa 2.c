/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 14:44:27 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/05 15:32:47 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_isnegative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static char	*makeint(char *tmp, int isnegative, int n, int len)
{
	while (n > 0)
	{
		tmp[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (isnegative)
		tmp[len] = '-';
	return (tmp);
}

char	*ft_itoa(int n)
{
	int		isnegative;
	char	*tmp;
	int		len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	isnegative = ft_isnegative(n);
	len = ft_intlen(n);
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	if (isnegative)
		n *= -1;
	tmp[len] = '\0';
	len--;
	makeint(tmp, isnegative, n, len);
	return (tmp);
}
