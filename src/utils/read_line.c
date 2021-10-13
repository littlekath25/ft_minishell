#include "shell.h"

char	*read_line(char *prompt)
{
	char	**env;
	char	*line;

	env = *g_shell->environ;
	line = readline(prompt);
	*g_shell->environ = env;
	return (line);
}
