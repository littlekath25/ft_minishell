/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:39:36 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/04 16:00:21 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
	Print the argument specified in argv to the stdout.
	-n flag removes the trailing newline.
*/
void	_echo_(char **argv)
{
	char	newline;
	int		i;

	newline = 1;
	argv++;
	while (*argv && (*argv)[0] == '-' && (*argv)[1] == 'n')
	{
		i = 2;
		while ((*argv)[i] == 'n')
			i++;
		if ((*argv)[i] != '\0')
			break ;
		newline = 0;
		argv++;
	}
	while (*argv)
	{
		printf("%s", *argv);
		argv++;
		if (*argv)
			printf(" ");
	}
	if (newline)
		printf("\n");
}
