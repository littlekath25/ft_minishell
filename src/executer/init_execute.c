/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_execute.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 16:38:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/05/05 18:43:05 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
#include <stdio.h>
#include <unistd.h>

void	init_execute(t_tree *trees)
{
	
}

int	main(int argc, char **args, char **path)
{
	// char	*pathstr = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki/ls";
	char	*pathstr = "/bin/zsh/ls";
	char	*argv[2];

	argv[0] = "ls";
	argv[1] = NULL;
	while (*path)
	{
		printf("%s\n", *path);
		path++;
	}
	if (execv(pathstr, argv))
		printf("error\n");
}
