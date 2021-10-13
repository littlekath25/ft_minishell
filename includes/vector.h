/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/19 09:19:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/10/13 15:38:03 by pspijkst      ########   odam.nl         */
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

t_vector	*vector_new(unsigned int bytesize);
void		*vector_getvalue(t_vector *vector, int index);
char		**vector_tostrarray(t_vector *vect);
t_vector	*vector_newptr(void);
void		vector_removeat(t_vector *vect, int index);
char		vector_add(t_vector *vector, void *data);
void		vector_free(t_vector *vector);
t_vector	*vector_realloc(t_vector *vector);
void		vector_clear(t_vector *vect);
int			vector_indexof(t_vector *vect, char *data);

#endif