/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/29 17:32:58 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/01 12:49:17 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

typedef struct s_dict
{
	char	*key;
	void	(*f)(char **argv);
}	t_dict;

void	env(char **env);

#endif