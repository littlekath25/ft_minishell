/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_split.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 19:26:22 by kfu           #+#    #+#                 */
/*   Updated: 2021/03/08 17:20:39 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split || !*split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}
