/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 13:06:31 by kfu           #+#    #+#                 */
/*   Updated: 2021/05/05 15:31:11 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_charfind(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*newstr(char *tmp, char const *str, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		tmp[i] = str[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*tmp;
	int		start;
	int		end;

	start = 0;
	if (!str)
		return (NULL);
	if (!set)
		return (ft_strdup(str));
	while (str[start] && ft_charfind(str[start], set))
		start++;
	end = ft_strlen(str);
	while (end > start && ft_charfind(str[end - 1], set))
		end--;
	tmp = (char *)malloc(end - start + 1);
	if (!tmp)
		return (NULL);
	newstr(tmp, str, start, end);
	return (tmp);
}
