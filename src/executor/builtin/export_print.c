#include <shell.h>

static void	st_insert_sorted(char **env, char *str, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		if (env[i] == NULL)
		{
			env[i] = str;
			break ;
		}
		else if (ft_strcmp(env[i], str) >= 0)
		{
			ft_memmove(env + i + 1, env + i, (lines - i - 1) * sizeof(char *));
			env[i] = str;
			break ;
		}
		else
			i++;
	}
}

static char	**st_env_cpy(char **env)
{
	int		i;
	int		lines;
	char	**cpy;

	lines = 0;
	while (env[lines])
		lines++;
	cpy = ft_calloc((lines + 1), sizeof(char *));
	if (!cpy)
		shell_exit(err_malloc);
	i = 0;
	while (env[i])
	{
		st_insert_sorted(cpy, env[i], lines);
		i++;
	}
	return (cpy);
}

/*
	Prints all export variables from environment variables list.
	This includes key-only variables.
*/
void	export_print(void)
{
	char	**env;
	int		i;

	env = *g_shell->environ;
	if (!env)
		return ;
	env = st_env_cpy(env);
	i = 0;
	while (env[i])
	{
		ft_putstr_fd("declare -x ", g_shell->io_fds[1]);
		ft_putendl_fd(env[i], g_shell->io_fds[1]);
		i++;
	}
	free(env);
}
