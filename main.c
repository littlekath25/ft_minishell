/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:12:07 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/05/05 16:39:19 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	t_tree	*trees;
	char	*buffer;
	int		result;

	result = 1;
	while (result > 0)
	{
		result = get_next_line(0, &buffer);
		if (result > 0)
		{
			trees = init_parser(buffer);
			if (trees == 0)
			{
				printf("Parse error\n");
				exit(0);
			}
			init_execute(trees);
			free(buffer);
		}
	}
	if (result == 0)
		printf("Result == 0\n");
	else if (result == -1)
		printf("Result == -1\n");
	return (1);
}
