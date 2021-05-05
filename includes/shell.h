/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:17:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/05/05 16:36:27 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_token
{
	struct s_token	*next;
	char			*data;
}	t_token;

typedef struct s_command
{
	struct s_command	*out;
	struct s_command	*in;
	struct s_command	*pipe;
	t_token				*tokens;
	int					outfd;
	int					infd;
}	t_command;

typedef struct s_tree
{
	t_command		*commands;
	struct s_tree	*next;
}	t_tree;

t_tree		*init_parser(char *buffer);
void		init_execute(t_tree *trees);

#endif
