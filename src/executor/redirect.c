#include "shell.h"

static t_bool	handle_in(t_command *cmd, t_redirect *rdr)
{
	int	fd;

	fd = open(rdr->fname, O_RDONLY);
	if (fd == -1)
	{
		print_perror(rdr->fname);
		g_shell->returnstatus = 1;
		return (false);
	}
	if (cmd->in_fd != STDIN_FILENO)
		close(cmd->in_fd);
	cmd->in_fd = fd;
	return (true);
}

static t_bool	handle_out(t_command *cmd, t_redirect *rdr)
{
	int	fd;

	if (rdr->type == rdr_append)
		fd = open(rdr->fname, O_RDWR | O_CREAT | O_APPEND, 0666);
	else
		fd = open(rdr->fname, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		print_perror(rdr->fname);
		g_shell->returnstatus = 1;
		return (false);
	}
	if (cmd->out_fd != STDOUT_FILENO)
		close(cmd->out_fd);
	cmd->out_fd = fd;
	return (true);
}

t_bool	handle_redirects(t_command *cmd)
{
	t_redirect	*rdr;

	rdr = cmd->redirects;
	while (rdr)
	{
		if (rdr->type == rdr_input)
		{
			if (handle_in(cmd, rdr) == false)
				return (false);
		}
		else if (rdr->type == rdr_output || rdr->type == rdr_append)
		{
			if (handle_out(cmd, rdr) == false)
				return (false);
		}
		rdr = rdr->next;
	}
	return (true);
}

void	close_unused_fds(t_command *cmd)
{
	if (cmd->in_fd != STDIN_FILENO)
		close(cmd->in_fd);
	if (cmd->out_fd != STDOUT_FILENO)
		close(cmd->out_fd);
}
