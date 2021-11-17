/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 16:34:19 by kfu           #+#    #+#                 */
/*   Updated: 2021/11/17 11:04:35 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	redirects_addnew(t_redirect **head, char *fname, t_rdrs rdr)
{
	t_redirect	*new;
	t_redirect	*iter;

	new = malloc(sizeof(t_redirect));
	if (!new)
		shell_exit(err_malloc);
	new->fname = fname;
	new->type = rdr;
	new->next = NULL;
	iter = *head;
	if (!iter)
		*head = new;
	else
	{
		iter = *head;
		while (iter->next)
			iter = iter->next;
		iter->next = new;
	}
}

static char	*get_next_token(t_parsing *info)
{
	char	*filename;

	while (*info->ptr == ' ')
		info->ptr++;
	filename = get_filename(info);
	return (filename);
}

static t_rdrs	get_rdr_type(t_parsing *info)
{
	if (*info->ptr == '>')
	{
		info->ptr++;
		if (*info->ptr == '>')
		{
			info->ptr++;
			return (rdr_append);
		}
		else
			return (rdr_output);
	}
	else
	{
		info->ptr++;
		if (*info->ptr == '<')
		{
			info->ptr++;
			return (rdr_heredoc);
		}
		else
			return (rdr_input);
	}
}

t_bool	set_redirects(t_parsing *info)
{
	char	*str;
	t_rdrs	rdr_type;

	rdr_type = get_rdr_type(info);
	str = get_next_token(info);
	if (!*str)
	{
		printf("syntax error near unexpected token `newline'\n");
		free(str);
		return (false);
	}
	if (rdr_type == rdr_heredoc)
	{
		heredoc_addnew(str);
		str = ft_strdup(HEREDOC_FNAME);
		if (!str)
			shell_exit(err_malloc);
		redirects_addnew(&info->current_cmd->redirects, str, rdr_input);
	}
	else
		redirects_addnew(&info->current_cmd->redirects, str, rdr_type);
	return (true);
}
