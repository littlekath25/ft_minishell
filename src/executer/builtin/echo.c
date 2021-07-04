/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/01 17:39:36 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/01 18:43:49 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../../libft/libft.h"

/*
	Print the argument specified in argv to the stdout, with a trailing newline.
*/
void	_echo_(char **argv)
{
	char	newline;

	newline = 1;
	argv++;
	if (ft_strcmp(*argv, "-n") == 0)
	{
		argv++;
		newline = 0;
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
