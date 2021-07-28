/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: katherine <katherine@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/28 22:16:18 by katherine     #+#    #+#                 */
/*   Updated: 2021/07/28 22:22:04 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	count_size_without_quotes(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] != '"')
			size++;
		i++;
	}
	return (size);
}

char	*copy_str_without_quotes(char *tmp, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '"')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	return (tmp);
}
