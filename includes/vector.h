/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 15:55:47 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/08 22:09:52 by pspijkst      ########   odam.nl         */
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

char		vector_add(t_vector *vector, void *data);
void		*vector_getvalue(t_vector *vector, int index);
t_vector	*vector_new(int bytesize);
void		*vector_getptr(t_vector *vector, int index);
t_vector	*vector_newptr(void);
void		vector_freeptr(t_vector *vector);
void		*vector_getvalue(t_vector *vector, int index);
void		vector_free(t_vector *vector);
t_vector	*vector_realloc(t_vector *vector);
char		vector_remove(t_vector *vect, int index);
char		**vector_tostrarray(t_vector *vect);

#endif
