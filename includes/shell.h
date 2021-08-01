/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:17:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/08/01 11:38:10 by pspijkst      ########   odam.nl         */
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
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_quotes
{
	int		i;
	int		j;
	int		size;
	char	*tmp;
}	t_quotes;

typedef enum e_states
{
	DULL,
	IN_WORD,
	IN_DOUBLE,
	IN_SINGLE,
	IN_PIPE,
	DONE,
	ERROR
}	t_states;

typedef enum e_error
{
	err_args = 1,
	err_malloc,
	err_pipe
}	t_error;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_tokens
{
	int		size;
	int		allocated;
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
	int					append;
	t_tokens			*tokens;
	struct s_command	*next;
}	t_command;

typedef struct s_shell
{
	t_command	*cmd;
	t_vector	*env;
	char		***environ;
}	t_shell;

t_shell		*g_shell;

void		error_and_exit(int error);
void		print_tokens(void);

void		init_shell(char **env);
void		init_prompt(void);

// COMMAND FUNCTIONS
void		read_command(void);
void		create_commands_list(char *line);
t_command	*create_new_command(void);
void		add_new_command(char *line);
void		add_back_command(t_command **dest, t_command *new);
void		delete_one_command(t_command **src, t_command *node);

// TOKEN FUNCTIONS
t_tokens	*create_new_token(void);
void		change_states(t_parsing *info);
void		change_pipe_state(t_parsing *info);
void		fill_in_tokens(t_parsing *info, t_tokens *tokens);
void		delete_redirect_token(char **pointers, int i);

// ITEM FUNCTIONS
void		make_new_item(t_parsing *info, t_tokens *tokens);
int			check_if_makes_new_item(t_parsing *info, t_tokens *tokens);
void		expand_items(t_tokens *tokens);
char		*delete_all_quotes(char *str);

// REDIRECT FUNCTIONS
void		set_redirects(void);
void		set_input_output(t_command *command);
void		set_input(t_command *command, int i);
void		set_output(t_command *command, int i);

// FREE FUNCTIONS
void		free_command_and_tokens(void);
void		free_command(void);
void		free_pipes(void);

// Executor
void		init_executor(void);

// UTILS
int			count_size_without_quotes(char *str);
char		*copy_str_without_quotes(char *tmp, char *str);
t_bool		is_valid_name(char *var);

#endif
