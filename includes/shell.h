/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:17:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/14 15:10:03 by katherine     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "builtin.h"

typedef enum e_states
{
	DULL,
	IN_WORD,
	IN_STRING
}	t_states;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_tokens
{
	size_t	size;
	size_t	allocated;
	char	*items[10];
}	t_tokens;

typedef struct s_command
{
	struct s_command	*pipe;
	int					in_fd;
	int					out_fd;
	t_tokens			*tokens;
	struct s_command	*prev;
	struct s_command	*next;
}	t_command;

typedef struct s_shell
{
	char		**env;
	t_command	*commands;
}	t_shell;

t_shell		*g_shell;

void		error_and_exit(int error);

// COMMAND FUNCTIONS
void		read_commands(void);
void		create_commands_list(char *line);
t_command	*create_new_command(void);
void		add_new_command(char *line);
void		add_back_command(t_command **dest, t_command *new);
void		delete_one_command(t_command **src, t_command *node);

typedef struct s_tree
{
	t_command		*commands;
	struct s_tree	*next;
}	t_tree;

// TOKEN FUNCTIONS
t_tree		*init_parser(char *buffer);
void		init_execute(t_tree *trees);
t_tokens	*create_new_token(void);
void		expand_tokens(t_tokens *tokens);
void		fill_in_tokens(char *line, t_tokens *tokens);

#endif
