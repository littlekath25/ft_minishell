/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:32:58 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/09/21 16:25:54 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "vector.h"

typedef struct s_dict
{
	char	*key;
	int		(*f)(char **argv);
}	t_dict;

void	*get_builtin(const char *key);
int		env_list_indexof(t_vector *vect, char *key);

int		_cd_(char **argv);
int		_echo_(char **argv);
int		_env_(char **argv);
int		_exit_(char **argv);
int		_export_(char **argv);
int		_pwd_(char **argv);
int		_unset_(char **argv);

#endif
