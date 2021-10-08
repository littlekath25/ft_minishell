#include "shell.h"

static int	get_exit_code(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus))
		return (128 + WTERMSIG(wstatus));
	else if (WIFSTOPPED(wstatus))
		return (WSTOPSIG(wstatus));
	return (-1);
}

void	wait_and_set_returnvalue(int pid)
{
	int		status;

	if (waitpid(pid, &status, 0) != -1)
		g_shell->returnstatus = get_exit_code(status);
	else
		shell_exit(err_fork);
}
