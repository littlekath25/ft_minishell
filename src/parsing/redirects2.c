/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 12:36:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/09 23:36:52 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	get_next_token(char **filename, t_parsing *info)
{
	char	*tmp;
	int		len;
	int		i;
	
	len = 0;
	i = 0;
	while (*info->ptr == ' ')
		info->ptr++;
	tmp = info->ptr;
	while (*tmp != ' ' && *tmp)
	{
		tmp++;
		len++;
	}
	*filename = ft_substr(info->ptr, 0, len);
	info->ptr = tmp;
}
