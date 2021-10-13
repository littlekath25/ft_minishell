#include "shell.h"

static void	set_fd(t_command *cmd)
{
	if (cmd->in_fd == STDIN_FILENO)
		cmd->in_fd = open(HEREDOC_FNAME, O_RDONLY);
}

void	handle_heredoc(t_command *cmd)
{
	char	*line;
	int		fd;

	if (cmd->delimiter != NULL)
	{
		fd = open(HEREDOC_FNAME, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (!fd)
			exit(1);
		while (1)
		{
			line = read_line("> ");
			if (!line)
				break ;
			if (ft_strcmp(line, cmd->delimiter) == 0)
			{
				free(line);
				break ;
			}
			ft_putendl_fd(line, fd);
			free(line);
		}
		close(fd);
		set_fd(cmd);
	}
}
