/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/05 13:17:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/10/08 13:52:27 by kfu           ########   odam.nl         */
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
# include <string.h>

# define BUFFER 1024

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_quotes
{
	int		i;
	int		j;
	int		size;
	char	*tmp;
}	t_quotes;

typedef enum e_error_states
{
	GENERAL_ERROR = 1,
	MISUSE_BUILTIN = 2,
	CANNOT_EXECUTE = 126,
	COMMAND_NOT_FOUND = 127,
	INVALID_ARG = 128,
	OUT_OF_RANGE = 256
}	t_error_states;

typedef enum e_redirects
{
	NONE,
	INPUT,
	OUTPUT,
	APPEND,
	DELIMITER
}	t_redirects;

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

typedef enum e_errorz
{
	err_args = 1,
	err_malloc,
	err_pipe,
	err_fork,
	err_exit
}	t_error;

typedef struct s_tokens
{
	int		size;
	int		allocated;
	char	**items;
}	t_tokens;

typedef struct s_parsing
{
	char			*ptr;
	enum e_states	state;
	int				argc;
	int				i;
	int				size;
	char			*buffer;
}	t_parsing;

typedef struct s_command
{
	struct s_command	*pipe;
	int					in_fd;
	int					out_fd;
	int					append;
	char				*delimiter;
	t_tokens			*tokens;
}	t_command;

typedef struct s_shell
{
	int					io_fds[2];
	int					returnstatus;
	t_command			*cmd;
	t_vector			*env_list;
	char				***environ;
	t_error_states		error_state;
	t_command			*dest;
	t_parsing			*info;
}	t_shell;

t_shell		*g_shell;

typedef struct s_envvar
{
	char	*key;
	char	*value;
	t_bool	is_append;
}	t_envvar;

// RENMOVE BEFORE EVAL
void		print_tokens(void);

void		shell_exit(int error);
void		print_tokens(void);

void		init_shell(char **env);
void		init_prompt(void);
void		init_command(t_command *new);

// CREATE FUNCTIONS
t_parsing	*create_new_info(char *line);
void		create_new_command_and_tokens(t_command **dest);
int			create_commands_list(char *line);
void		create_new_pipe(t_parsing *info);

// PARSE FUNCTIONS
void		make_new_token(t_parsing *info);
void		dull_functions(t_parsing *info);
void		double_functions(t_parsing *info);
void		single_functions(t_parsing *info);
int			pipe_functions(t_parsing *info);
int			word_functions(t_parsing *info);
int			fill_in_tokens(t_parsing *info);
t_bool		end_of_token(t_parsing *info);
t_bool		convert_variable(t_parsing *info);
void		variable_checker(t_parsing *info);
t_bool		is_redirect(t_parsing *info);
void		copy_to_buffer(t_parsing *info);
void		expand_buffer(t_parsing *info);
t_redirects	which_redirect(char *line);

// ITEM FUNCTIONS
void		expand_items(t_tokens *tokens);
int			set_redirects(void);

// FREE FUNCTIONS
void		free_command_and_tokens(void);

// Executor
void		init_executor(void);

// UTILS
t_bool		is_valid_key(char *var);
t_bool		is_valid_key_l(char *var, unsigned int l);
void		activate_signals(void);
void		deactivate_signals(void);
void		print_error_token(char token);
void		delete_redirect_token(char **pointers, int i);

#endif
