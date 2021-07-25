/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:50:10 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/25 12:18:22 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../includes/builtin.h"
#include "../../../includes/shell.h"

static char	*st_format_arg(char *arg, int len)
{
	char	*formatted;

	formatted = malloc(ft_strlen(arg) + 3);
	if (!formatted)
		exit(0);
	ft_memcpy(formatted, arg, len);
	formatted[len] = '=';
	formatted[len + 1] = 0;
	printf("\n%s\n", formatted);
}

/*
	Sets environment variable.
*/
void	_export_(char **argv)
{
	char	*end;
	int		i;
	int		strlen;

	if (argv[0] == 0)
		_env_(argv);
	while (*argv)
	{
		strlen = ft_strlen(*argv);
		end = ft_strnstr(*argv, "=", strlen);
		if (end != NULL)
		{
			st_format_arg(*argv, strlen);
			i = end - *argv;
		}
		else
			i = strlen;
		i = vector_indexof(g_shell->env.env, argv[1], i);
		if (i != -1)
		{
		}
		argv++;
	}
	// if (i != -1)
	// {
	// 	end = ft_strnstr()
	// 	free(vector_getvalue(g_shell->env, i));
	// 	vector_removeat(g_shell->env, i);
	// }
	// if (!vector_add(g_shell->env, argv[1]))
	// {
	// 	printf("Error in Export\n"); // debug
	// 	exit(0);
	// }
}
