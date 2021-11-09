/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 12:36:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/11/03 14:54:11 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	set_redirects(void)
{
	return (iterate_tokens(0, NULL));
}
