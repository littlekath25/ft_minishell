/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:32:58 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/04 16:37:17 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "vector.h"

typedef struct s_dict
{
	char	*key;
	void	(*f)(char **argv);
}	t_dict;

void	*get_builtin(const char *key);
int		env_list_indexof(t_vector *vect, char *key);

void	_cd_(char **argv);
void	_echo_(char **argv);
void	_env_(char **argv);
void	_exit_(char **argv);
void	_export_(char **argv);
void	_pwd_(char **argv);
void	_unset_(char **argv);

#endif