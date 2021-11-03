#include "shell.h"

void	heredoc_addnew(char *delimiter)
{
	t_heredoc	*new;
	t_heredoc	*tmp;

	new = malloc(sizeof(t_heredoc));
	if (!new)
		shell_exit(err_malloc);
	new->delimiter = delimiter;
	new->next = NULL;
	if (g_shell->heredocs == NULL)
		g_shell->heredocs = new;
	else
	{
		tmp = g_shell->heredocs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static void	process_heredoc(t_heredoc *heredoc)
{
	char	*line;
	int		fd;

	unlink(HEREDOC_FNAME);
	fd = open(HEREDOC_FNAME, O_CREAT | O_WRONLY, 0666);
	if (fd == -1)
		shell_exit(err_open);
	while (1)
	{
		line = read_line("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, heredoc->delimiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
}

void	handle_heredoc(t_command *cmd)
{
	t_heredoc	*heredoc;

	if (g_shell->heredocs != NULL)
	{
		heredoc = g_shell->heredocs;
		while (1)
		{
			process_heredoc(heredoc);
			if (heredoc->next)
				heredoc = heredoc->next;
			else
			{
				if (cmd->in_fd == STDIN_FILENO)
				{
					cmd->in_fd = open(HEREDOC_FNAME, O_RDONLY);
					if (cmd->in_fd == -1)
						shell_exit(err_open);
				}
				break ;
			}
		}
	}
}
