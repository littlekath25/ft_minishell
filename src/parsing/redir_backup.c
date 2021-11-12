/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 16:34:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/11 09:15:39 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*get_next_token(t_parsing *info)
{
	char	*tmp;
	char	*filename;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (*info->ptr == ' ')
		info->ptr++;
	tmp = info->ptr;
	while (ft_isalnum(*tmp))
	{
		tmp++;
		len++;
	}
	if (len > 0)
		filename = ft_substr(info->ptr, 0, len);
	else
	{
		print_err_syntax();
		filename = NULL;
	}
	info->ptr = tmp;
	return (filename);
}

static t_bool	set_delimiter(t_parsing *info)
{
	char	*delimiter;

	info->ptr++;
	delimiter = get_next_token(info);
	if (!delimiter)
		return (false);
	heredoc_addnew(delimiter);
	if (info->current_cmd->in_fd != STDIN_FILENO)
		close(info->current_cmd->in_fd);
	info->current_cmd->in_fd = STDIN_FILENO;
	return (true);
}

static t_bool	set_output(t_parsing *info, int append)
{
	int		fd;
	char	*filename;

	fd = -1;
	if (append)
		info->ptr++;
	filename = get_next_token(info);
	if (!filename)
		return (false);
	if (append)
		fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0666);
	else
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		print_perror(filename);
		free(filename);
		return (true);
	}
	else
		info->current_cmd->out_fd = fd;
	free(filename);
	return (true);
}

static t_bool	set_input(t_parsing *info)
{
	int		fd;
	char	*filename;

	fd = -1;
	filename = get_next_token(info);
	if (!filename)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_perror(filename);
		free(filename);
		info->current_cmd->in_fd = fd;
		return (true);
	}
	else
		info->current_cmd->in_fd = fd;
	free(filename);
	return (true);
}

t_bool	set_redirects(t_parsing *info)
{
	int	append;

	append = 0;
	if (*info->ptr == '>')
	{
		info->ptr++;
		if (*info->ptr == '>')
			append = 1;
		return (set_output(info, append));
	}
	else if (*info->ptr == '<')
	{
		info->ptr++;
		if (*info->ptr == '<')
			return (set_delimiter(info));
		else
			return (set_input(info));
	}
	return (true);
}
