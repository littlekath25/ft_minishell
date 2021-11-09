/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 16:34:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/09 23:56:18 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	get_next_token(char **filename, t_parsing *info)
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

static int	set_delimiter(t_parsing *info)
{
	char	*dlmtr_dup;

	info->ptr++;
	get_next_token(&dlmtr_dup, info);
	if (*dlmtr_dup)
	{
		heredoc_addnew(dlmtr_dup);
		if (g_shell->dest->in_fd != STDIN_FILENO)
			close(g_shell->dest->in_fd);
		g_shell->dest->in_fd = STDIN_FILENO;
	}
	else
	{
		printf("syntax error near unexpected token `newline'\n");
		return (-1);
	}
	return (1);
}

static int	set_output(t_parsing *info, int append)
{
	int		fd;
	char	*filename;

	fd = -1;
	if (append)
		info->ptr++;
	get_next_token(&filename, info);
	if (*filename)
	{
		if (append)
			fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0666);
		else
			fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (fd == -1)
		{
			printf("syntax error near unexpected token `newline'\n");
			return (-1);
		}
		else
			g_shell->dest->out_fd = fd;
	}
	return (1);
}

static int	set_input(t_parsing *info)
{
	int		fd;
	char	*filename;

	fd = -1;
	get_next_token(&filename, info);
	if (*filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			printf("syntax error near unexpected token `newline'\n");
			return (-1);
		}
		else
			g_shell->dest->in_fd = fd;
	}
	return (1);
}

int	set_redirects(t_parsing *info)
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
			set_delimiter(info);
		else
			set_input(info);
	}
	return (1);
}
