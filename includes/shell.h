/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:17:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/01 18:27:47 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "builtin.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_command
{
	struct s_command	*prev;
	struct s_command	*next;
	char				**argv;
	char				**env;
	int					outfd;
	int					infd;
}	t_command;

typedef struct s_tree
{
	t_command		*commands;
	struct s_tree	*next;
}	t_tree;

typedef struct s_shell
{
	char	**env;
}	t_shell;

t_tree		*init_parser(char *buffer);
void		init_execute(t_tree *trees);

#endif
