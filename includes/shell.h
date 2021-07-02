/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:17:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/02 12:30:41 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_command
{
	struct s_command	*pipe;
	char				**tokens;
	int					in_fd;
	int					out_fd;
	struct s_command	*previous;
	struct s_command	*next;
}	t_command;

typedef struct s_shell
{
	char		**env;
	t_command	*commands;
}	t_shell;

void		error_and_exit(int error);

// COMMAND FUNCTIONS
t_command	*create_new_command(t_command *new);
void		add_new_command(char *line, t_shell *shell);
void		add_back_command(t_shell *shell, t_command *new);

#endif
