/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 11:37:17 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/05 15:33:18 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static double	calc_float(const char *str, double res, \
double decimal, int sign)
{
	int	fraction;
	int	divisor;

	fraction = 0;
	divisor = 1;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			if (fraction)
			{
				decimal = decimal * 10 + (*str - '0');
				divisor *= 10;
			}
			else
				res = res * 10 + (*str - '0');
		}
		else if (*str == '.')
			fraction = 1;
		++str;
	}
	return (sign * (res + decimal / divisor));
}

static int	calc_sign(const char **str, int sign)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

double	ft_atof(const char *str)
{
	double	res;
	double	decimal;
	int		sign;

	res = 0;
	decimal = 0;
	sign = 1;
	sign = calc_sign(&str, sign);
	res = calc_float(str, res, decimal, sign);
	return (res);
}
