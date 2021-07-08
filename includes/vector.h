/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 15:55:47 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 15:58:13 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"

typedef struct s_vector
{
	void	*memb;
	char	bytesize;
	char	isptr;
	int		nmemb;
	int		size;
}	t_vector;



#endif
