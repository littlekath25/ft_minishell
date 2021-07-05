/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:32:58 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/01 18:30:22 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

typedef struct s_dict
{
	char	*key;
	void	(*f)(char **argv);
}	t_dict;

void	*get_builtin(const char *key);

void	_cd_(char **argv);
void	_echo_(char **argv);
void	_env_(char **argv);
void	_exit_(char **argv);
void	_export_(char **argv);
void	_pwd_(char **argv);
void	_unset_(char **argv);

#endif