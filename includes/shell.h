/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:17:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/07/19 11:40:04 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "builtin.h"
# include "vector.h"

typedef enum e_states
{
	DULL,
	IN_WORD,
	IN_STRING,
	IN_PIPE,
	DONE
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
	char	**items;
}	t_tokens;

typedef struct s_parsing
{
	char		*ptr;
	char		*start;
	int			argc;
	t_states	state;
}	t_parsing;

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
	t_vector	*env;
	t_command	*commands;
}	t_shell;

t_shell		*g_shell;

void		error_and_exit(int error);
void		print_tokens(void);

// COMMAND FUNCTIONS
void		read_commands(void);
void		create_commands_list(char *line);
t_command	*create_new_command(void);
void		add_new_command(char *line);
void		add_back_command(t_command **dest, t_command *new);
void		delete_one_command(t_command **src, t_command *node);

// TOKEN FUNCTIONS
t_tokens	*create_new_token(void);
void		expand_tokens(t_tokens *tokens);
void		fill_in_tokens(t_parsing *info, t_tokens *tokens);

#endif
