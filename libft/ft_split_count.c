/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_count.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 15:29:42 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 15:30:30 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_split_count(char **splits)
{
	int	count;

	count = 0;
	while (splits[count])
		count++;
	return (count);
}
