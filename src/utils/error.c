/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 16:42:28 by kfu           #+#    #+#                 */
/*   Updated: 2021/06/29 16:46:52 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_and_exit(int error)
{
	if (error == 1)
		printf("Please execute without arguments\n");
}
