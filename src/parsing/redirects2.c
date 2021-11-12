/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 13:56:35 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/12 14:30:54 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_bool	word_file_functions(t_parsing *info)
{
	if (*info->ptr == '"')
		info->state = IN_DOUBLE;
	else if (*info->ptr == '\'')
		info->state = IN_SINGLE;
	else if (is_redirect(info))
		return (false);
	else
		copy_to_buffer(info);
	return (true);
}

static t_bool	single_file_functions(t_parsing *info)
{
	if (*info->ptr == '\'')
	{
		info->ptr++;
		return (false);
	}
	else
		copy_to_buffer(info);
	return (true);
}

static t_bool	double_file_functions(t_parsing *info)
{
	if (*info->ptr == '"')
	{
		info->ptr++;
		return (false);
	}
	else
		copy_to_buffer(info);
	return (true);
}

static t_bool	write_to_buffer(t_parsing *info)
{
	if (info->state == IN_SINGLE)
		return (single_file_functions(info));
	else if (info->state == IN_DOUBLE)
		return (double_file_functions(info));
	else
		return (word_file_functions(info));
}

char	*get_filename(t_parsing *info)
{
	char	*filename;
	t_bool	status;

	filename = NULL;
	while (*info->ptr != ' ' && *info->ptr)
	{
		status = write_to_buffer(info);
		if (status == false)
			break ;
		info->ptr++;
	}
	filename = ft_strdup(info->buffer);
	ft_bzero(info->buffer, info->size);
	info->state = DULL;
	info->i = 0;
	return (filename);
}
